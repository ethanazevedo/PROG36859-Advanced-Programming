#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Player{
    private:
        string name;
        int score;
        static int totalScore;
    public: 
        
        Player(string n, int s): name(n), score(s){ totalScore+= s; };

        void addScore(int p){
            score = score + p;
            totalScore = totalScore + p;
        }

        friend void displayPlayer(const Player& p);


};

int Player::totalScore = 0;

void displayPlayer(const Player& p){
    cout << "Player: " << p.name << ", Score: " << p.score << endl;
    cout << "Total Score: " << Player::totalScore << endl;
}

int main(){
   
    Player p1("bob", 0);
    Player p2("joe", 0);
    Player p3("son", 0);

    p1.addScore(10);
    p2.addScore(20);
    p3.addScore(15);

    displayPlayer(p1);
    displayPlayer(p2);
    displayPlayer(p3);


    return 0;
}