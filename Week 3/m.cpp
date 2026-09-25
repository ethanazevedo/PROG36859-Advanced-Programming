/*
3 – Multiple Inheritance (Smart Device):

Create two base classes:

Camera – function takePhoto() prints "Taking photo..."
MusicPlayer – function playMusic() prints "Playing music..."
Create a derived class SmartPhone that inherits from both Camera and MusicPlayer, 
and adds a member string model. Add a function showModel() to display the phone model.

Add a function info() to all three classes to print the device information. 
The info() function in SmartPhone should call the info() functions of the other two classes.

In main(): Create a SmartPhone object, call takePhoto(), playMusic(),showModel(), and info().

*/

#include <iostream>
#include <string>
#include <memory>

using namespace std;

class Camera{
    protected:
        int megapixels;
    public:
        Camera(int m): megapixels(m) {};

        void takePhoto() const{
            cout << "Taking photo... " << endl;
        }

        void info() const{
            cout << "Megapixels: " << megapixels << endl;
        }
};

class MusicPlayer{
    protected:
        string genre;
    public:
        MusicPlayer(string g): genre(g) {};

        void playMusic() const{
            cout << "Playing music... " << endl;
        }

        void info() const{
            cout << "Genre of music: " << genre << endl;
        }      
};

class SmartPhone : public Camera, public MusicPlayer{
    protected:
        string model;
    public:
        SmartPhone(string mo, string g, int m): Camera(m), MusicPlayer(g), model(mo) {};

        void ShowModel() const {
            cout << "Phone model: " << model << endl;
        }

        void info() const{
            cout << "Phone info: \n " << Camera::megapixels << "\n " << MusicPlayer::genre << "\n " << "Phone model: " << model << endl;
        }
};

int main(){

    SmartPhone p1("Iphone 18 pro max", "Rap", 48);

    p1.takePhoto();
    p1.playMusic();
    p1.ShowModel();
    p1.info();


    return 0;
}