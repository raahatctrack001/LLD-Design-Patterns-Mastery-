#include<iostream>

using namespace std;

class Projector {
public:
    void on() {
        cout << "Projector ON\n";
    }
};

class SoundSystem {
public:
    void on() {
        cout << "Sound System ON\n";
    }
};

class DVDPlayer {
public:
    void play() {
        cout << "DVD Playing\n";
    }
};

class HomeTheaterFacade {

private:

    Projector projector;
    SoundSystem sound;
    DVDPlayer dvd;

public:

    void watchMovie() {

        projector.on();

        sound.on();

        dvd.play();

        cout << "Movie Started\n";
    }
};

int main() {

    HomeTheaterFacade theater;

    theater.watchMovie();
}