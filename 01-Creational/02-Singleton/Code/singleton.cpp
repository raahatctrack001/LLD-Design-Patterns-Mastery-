#include<iostream>

using namespace std;

//Meyers Singleton
class Singleton {

private:

    Singleton() {}

public:

    Singleton(const Singleton&) = delete; //avoid cloning if done deletes it
    Singleton& operator=(const Singleton&) = delete; //avoid assignment if assigned then deletes it

    static Singleton& getInstance() {

        static Singleton instance;

        return instance;
    }

    void display() {
        cout << "Singleton Instance\n";
    }
};