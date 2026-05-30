#include <iostream>
#include <vector>
#include <memory>
#include <unordered_map>

using namespace std;

class AsteroidType {

private:

    string texture;
    string model;
    string color;

public:

    AsteroidType(
        const string& texture,
        const string& model,
        const string& color
    )
        : texture(texture),
          model(model),
          color(color)
    {}

    void render(
        int x,
        int y,
        int size
    ) {

        cout
            << "Rendering Asteroid => "
            << "Texture: " << texture
            << ", Model: " << model
            << ", Color: " << color
            << ", Position: (" << x << "," << y << ")"
            << ", Size: " << size
            << endl;
    }
};

class AsteroidFactory {

private:

    static unordered_map<
        string,
        shared_ptr<AsteroidType>
    > asteroidTypes;

public:

    static shared_ptr<AsteroidType>
    getAsteroidType(
        const string& texture,
        const string& model,
        const string& color
    ) {

        string key = texture + "|" + model + "|" + color;

        //
        // Reuse existing flyweight
        //

        if(
            asteroidTypes.find(key)
            != asteroidTypes.end()
        ) {

            return asteroidTypes[key];
        }

        //
        // Create new flyweight
        //

        cout
            << "Creating NEW Flyweight: "
            << key
            << endl;

        asteroidTypes[key] =
            make_shared<AsteroidType>(
                texture,
                model,
                color
            );

        return asteroidTypes[key];
    }
};

class Asteroid {

private:

    int x;
    int y;
    int size;

    shared_ptr<AsteroidType>
        type;

public:

    Asteroid(
        int x,
        int y,
        int size,
        shared_ptr<AsteroidType> type
    )
        : x(x),
          y(y),
          size(size),
          type(type)
    {}

    void render() {
        type->render(
            x,
            y,
            size
        );
    }
};

unordered_map<
    string,
    shared_ptr<AsteroidType>
>
AsteroidFactory::asteroidTypes;

int main() {

    vector<Asteroid> asteroids;

    //
    // Shared flyweights
    //

    auto rockType =
        AsteroidFactory::getAsteroidType(
            "rock_texture.png",
            "rock_model.obj",
            "gray"
        );

    auto iceType =
        AsteroidFactory::getAsteroidType(
            "ice_texture.png",
            "ice_model.obj",
            "blue"
        );

    //
    // Thousands of asteroids
    //

    for(int i = 0; i < 5; i++) {

        asteroids.emplace_back(
            rand() % 1000,
            rand() % 1000,
            rand() % 50,
            rockType
        );
    }

    for(int i = 0; i < 5; i++) {

        asteroids.emplace_back(
            rand() % 1000,
            rand() % 1000,
            rand() % 50,
            iceType
        );
    }

    //
    // Render all
    //

    for(auto& asteroid : asteroids) {

        asteroid.render();
    }

    return 0;
}