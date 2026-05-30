#include <iostream>
#include <memory>

using namespace std;

class ITexture {

public:

    virtual void render() = 0;
    virtual ~ITexture() {}
};

class RealTexture
    : public ITexture {

private:

    string filename;
    void loadFromDisk() {

        cout
            << "Loading HIGH RES texture from disk: "
            << filename
            << endl;
    }

public:

    RealTexture(
        const string& file
    )
        : filename(file)
    {

        loadFromDisk();
    }

    void render() override {

        cout
            << "Rendering texture: "
            << filename
            << endl;
    }
};

class TextureProxy
    : public ITexture {

private:

    string filename;
    unique_ptr<RealTexture>
        realTexture;

public:

    TextureProxy(
        const string& file
    )
        : filename(file)
    {}

    void render() override {

        //
        // Lazy loading
        //

        if(!realTexture) {

            cout
                << "[Proxy] Lazy loading texture..."
                << endl;

            realTexture =
                make_unique<RealTexture>(
                    filename
                );
        }

        realTexture->render();
    }
};

int main() {

    ITexture* texture =
        new TextureProxy(
            "boss_enemy.png"
        );

    cout
        << "Game started..."
        << endl;

    cout
        << "Texture not loaded yet"
        << endl;

    cout << endl;

    //
    // First render triggers loading
    //

    texture->render();
    cout << endl;

    //
    // Already loaded now
    //

    texture->render();
    delete texture;

    return 0;
}