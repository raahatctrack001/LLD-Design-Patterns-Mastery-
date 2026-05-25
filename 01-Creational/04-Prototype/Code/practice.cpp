#include<iostream>
#include<vector>

using namespace std;

class NPC {
    protected:
        string type;
        int health;
        int damage;

    public:
        virtual NPC *clone() = 0;
        virtual void showDetails() = 0;
        ~NPC() {};
};

class Soldier: public NPC{
    private:
        string weapon;
        string armourType;

    public: 
        Soldier(int health, int damage, string weapon, string at){
            this->type = "soldier";
            this->health = health;
            this->damage = damage;
            this->weapon = weapon;
            this->armourType = at;

            cout << "Heavy Soldier Initialization...\n";
            cout << "Loading textures...\n";
            cout << "Loading AI configs...\n";
            cout << "Loading animations...\n\n";
        }

        NPC* clone() override {
            return new Soldier(*this);
        }

        void showDetails() override {

            cout << "====== SOLDIER NPC ======\n";

            cout << "Health: " << health << endl;
            cout << "Damage: " << damage << endl;
            cout << "Weapon: " << weapon << endl;
            cout << "Armor: " << armourType << endl;

            cout << endl;
        }

        ~Soldier(){
            delete this;
        }

};

class Zombie: public NPC{
    private:
        int infectionLevel;
    
    public:
        Zombie(int health, int damage, int infectionLevel){
            this->type = "zombie";
            this->health = health;
            this->damage = damage;
            this->infectionLevel = infectionLevel;

            cout << "Heavy Zombie Initialization...\n";
            cout << "Loading textures...\n";
            cout << "Loading AI configs...\n";
            cout << "Loading animations...\n\n";
        }

        NPC *clone() override{
            return new Zombie(*this);
        }

        void showDetails() override {

            cout << "====== ZOMBIE NPC ======\n";

            cout << "Health: " << health << endl;
            cout << "Damage: " << damage << endl;
            cout << "Infection Level: " << infectionLevel << endl;
            cout << endl;
        }

        ~Zombie(){
            delete this;
        }
};

int main(){
    NPC *soldier =
        new Soldier(
            100, 
            0,
            "MMG-1000",
            "Titanium vest"
        );

    NPC *zombie = 
        new Zombie(
            100,
            0,
            80
        );
    

    vector<NPC*> players;
    for(int i = 0; i < 10; i++){
        players.push_back(soldier->clone());
    }

    for(int i = 0; i < 100; i++){
        players.push_back(zombie->clone());
    }

    for(auto &player: players){
        player->showDetails();
        delete player;
    }

    

    return 0;
}