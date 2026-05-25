#include<iostream>
#include<string>
#include<vector>

using namespace std;

class NPC {

protected:

    string type;
    int health;
    int damage;

public:

    virtual NPC* clone() = 0;
    virtual void showDetails() = 0;
    virtual ~NPC() {}
};


class Soldier : public NPC {

private:

    string weapon;
    string armorType;

public:

    Soldier(
        int health,
        int damage,
        string weapon,
        string armorType
    ) {

        this->type = "Soldier";
        this->health = health;
        this->damage = damage;
        this->weapon = weapon;
        this->armorType = armorType;

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
        cout << "Armor: " << armorType << endl;

        cout << endl;
    }
};




class Zombie : public NPC {

private:

    int infectionLevel;

public:

    Zombie(
        int health,
        int damage,
        int infectionLevel
    ) {

        this->type = "Zombie";
        this->health = health;
        this->damage = damage;
        this->infectionLevel = infectionLevel;

        cout << "Heavy Zombie Initialization...\n";
        cout << "Loading zombie textures...\n";
        cout << "Loading horror sounds...\n";
        cout << "Loading attack animations...\n\n";
    }


    NPC* clone() override {

        return new Zombie(*this);
    }


    void showDetails() override {

        cout << "====== ZOMBIE NPC ======\n";

        cout << "Health: " << health << endl;
        cout << "Damage: " << damage << endl;
        cout << "Infection Level: "
             << infectionLevel << endl;

        cout << endl;
    }
};



int main() {


    NPC* soldierPrototype =
        new Soldier(
            200,
            50,
            "AK-47",
            "Titanium Armor"
        );

    NPC* zombiePrototype =
        new Zombie(
            300,
            40,
            95
        );

    vector<NPC*> gameNPCs;

    for(int i = 0; i < 3; i++) {

        gameNPCs.push_back(
            soldierPrototype->clone()
        );
    }

    for(int i = 0; i < 20; i++) {

        gameNPCs.push_back(
            zombiePrototype->clone()
        );
    }

    for(auto npc : gameNPCs) {

        npc->showDetails();
    }


    delete soldierPrototype;
    delete zombiePrototype;

    for(auto npc : gameNPCs) {

        delete npc;
    }

    return 0;
}