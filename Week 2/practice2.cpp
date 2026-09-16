#include <iostream>
#include <string>

using namespace std;

class GamePlayer{
    private:
        string username;
        int points;
        static int totalPoints;
    public:
        GamePlayer(string n, int p): username(n), points(p){ totalPoints+=p; };


        void addPoints(int p){
            points+=p;
            totalPoints+=p;
        }

        friend void displayPlayer(const GamePlayer& p);


};


int GamePlayer::totalPoints = 0;

void displayPlayer(const GamePlayer& p){
    cout << "Username: " << p.username << endl;
    cout << "Points: " << p.points << endl;
    cout << "Total Points: " << GamePlayer::totalPoints << endl;

}




int main(){


    GamePlayer p1("Alex", 100);
    GamePlayer p2("Bob", 150);
    GamePlayer p3("Charlie", 75);

    p1.addPoints(50);
    p2.addPoints(25);
    p3.addPoints(100);

    displayPlayer(p1);
    displayPlayer(p2);
    displayPlayer(p3);


    return 0; 
}