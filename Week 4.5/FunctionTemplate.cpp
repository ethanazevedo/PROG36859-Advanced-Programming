#include <iostream>
#include <string>
using namespace std;

template <typename T>
T maxValue(T a, T b){
    if (a > b)
        return a;
    else
        return b;
}

int main(){

    cout << maxValue(10, 20) << endl;
    cout << maxValue(3.14, 2.71) << endl;
    cout << maxValue(string("apple"), string("banana")) << endl;

    return 0;
}