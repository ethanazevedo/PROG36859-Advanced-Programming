#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

/*
STL - Standard Template Library
- contains generic templates 

1. containers: data structures for storing and organizing a collection of data
  - vector, map, array, set
  - linked list, stack, queue, deque

2. iterator: used to access (loop through) elements in collection
  - like pointer, operations: *, ->, arithmetics (+, -, +=, -=, ++, --)
  - types: random, bidirectional, forward, reverse

3. algorithms: operations on data in collection
  - sort, search, shuffle, replace, reverse, merge, partition, ...
*/

class Hero {
private:
  string name;
  double power;
public:
  Hero(string n = "No-Name Hero", double p = 1.0) : name(n), power(p) {}
  double getPower() const { return power; }
  void print() const { cout << "Hero: " << name << ", " << power << endl; }
};

vector<Hero> getPowerfulHeros(const vector<Hero>& heros, double powerThreshold) {
  vector<Hero> temp;
  for (const auto& h : heros)
    if (h.getPower() > powerThreshold)
      temp.push_back(h);
  return temp;
}


int main() {
  //vector: like list in Python, dynamic array (size can be changed)

  //create, size(), [indexing], .at(ind)
  vector<int> v1 = {2, 3, 5, 7, 11, 13};
  cout << "Size: " << v1.size() << endl; 
  cout << v1[0] << endl; //retrieve
  v1[v1.size() - 1] += 10; //update
  int x = v1.at(0) + v1.at(1); //.at() has bound checking
  v1.at(1) = 33; 

  //push_back(), pop_back()
  v1.push_back(17); //append
  v1.pop_back(); //remove last

  //loop through: regular for, range-based for 
  for (int i = 0; i < v1.size(); i++)
    cout << v1[i] << endl;
  
  for (int x : v1) 
    cout << x << endl;
  for (int& a : v1) 
    a *= 10;
  for (const auto& a : v1) //no modification, app deduces type (auto)
    cout << a << endl;
  
  //iterator
  vector<int>::iterator it1 = v1.begin();
  auto it2 = v1.begin();
  cout << *it2 << endl;
  it2 += 2;
  it2++; 
  *it2 += 10;

  for (auto it = v1.begin(); it != v1.end(); it++)
    cout << *it << endl;
  
  //insert, erase
  v1.insert(v1.begin() + 2, 12345);
  v1.erase(v1.begin());

  //vector of objects
  vector<Hero> heros = {Hero("Spiderman", 8.5), Hero("Superman", 9.2), 
                        Hero("Supergirl", 9.9), Hero("Hulk", 9.4)};
  heros.insert(heros.begin(), Hero("Batman", 7.5)); 
  for (const auto& h : heros) 
    h.print();
  
  //     push_back          vs.  emplace_back
  //     copy existing obj       create new obj in-place
  heros.push_back(Hero("Ironman", 9.4));
  heros.emplace_back("Antman", 6.2);
  for (auto it = heros.begin(); it != heros.end(); it++)
    it->print();

  //vector with function
  auto selectedHeros = getPowerfulHeros(heros, 8.5);
  cout << string(40, '-') << '\n';
  for (const auto& h : selectedHeros)
    h.print();


  //map: like dictionary in Python (key-value pairs)
  //- 1) key is unique; 2) sorted

  //create, size(), [key], .at(key)
  map<int, string> students = { {100, "Alex"}, {101, "Bob"}, {102, "Cendy"}, {103, "David"} };
  string name = students[102]; //retrieve
  students[103] = "Anna"; //update
  students[104] = "Ethan"; //insert

  //insert, erase, emplace
  students.insert({99, "Jack"});
  students.erase(101); 
  students.emplace(200, "Smith");

  //for loops
  for (auto& ele : students)
    cout << ele.first << ": " << ele.second << endl; //.first = key, .second = value
  for (auto& [k, v] : students) //new standard
    cout << k << "->" << v << endl;
  for (auto it = students.begin(); it != students.end(); it++)
    cout << it->first << ": " << it->second << endl;

  //map with objects
  //- key: comparable (overload operator<)
  //- value: default constructor
  map<string, Hero> heroMap = { {"FAST1001", Hero("Anna", 7.2)}, 
                                {"FAST1002", Hero("Banna", 8.3)},
                                {"FAST0001", Hero("Canna", 9.4)}};
  heroMap.insert({"FAST2345", Hero("Danna", 6.5)});
  heroMap.emplace("FAST3456", Hero("Eanna", 8.2));
  //try_emplace: new standard

  for (const auto& [id, hero] : heroMap) {
    cout << id << "\t: ";
    hero.print();
  }

}