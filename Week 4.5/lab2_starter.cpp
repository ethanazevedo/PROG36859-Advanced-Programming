/*
Write the following 3 classes. Check the class diagram for details.

1) Abstract base class Game
- Protected member: name (string)
- Constructor sets the name
- Pure virtual function play()
- Regular function getName() returning the name

2) Derived classes

2.a) BoardGame
- Private member: numPlayers (int)
- Constructor sets name and numPlayers
- Implements play() to print:
    Playing <name> with <numPlayers> players on a board

2.b) VideoGame
- Private member: platform (string, e.g., "PC", "PS5")
- Constructor sets name and platform
- Implements play() to print:
    Playing <name> on <platform>

// Note: Do NOT modify any provided code
*/
#include <iostream>
#include <string>
using namespace std;

// TODO: Abstract base class - Game


class Game{
    protected:
        string name;
    public:
        Game(const string& n): name(n) {};

        virtual ~Game(){
            nullptr;
        }

        virtual void play() const = 0;

        string getName() const {
            return name;
        }
};

// TODO: Derived class 1 - BoardGame

class BoardGame : public Game{
    private:
        int numPlayers;
    public:
        BoardGame(const string& n, int p): numPlayers(p), Game(n){};

        void play() const{
            cout << "Playing " << Game::name << " with " << numPlayers << " players on a board" << endl;
        }

};

// TODO: Derived class 2 - VideoGame

class VideoGame : public Game{
    private:
        string platform;
    public: 
        VideoGame(const string& n, const string& p): platform(p), Game(n){};

        void play() const{
            cout << "Playing " << Game::name << " on " << platform << endl;
        }

};

/*
Expected Output:
    Playing Chess with 2 players on a board   
    Playing Monopoly with 4 players on a board
    Playing Call of Duty on PlayStation 5
*/

int main() {
    Game* games[3];
    games[0] = new BoardGame("Chess", 2);
    games[1] = new BoardGame("Monopoly", 4);
    games[2] = new VideoGame("Call of Duty", "PlayStation 5");

    for (int i = 0; i < 3; ++i)
        games[i]->play();

    for (int i = 0; i < 3; ++i)
        delete games[i];
}
