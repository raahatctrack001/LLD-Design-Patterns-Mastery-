#include <iostream>
#include <vector>

using namespace std;

class FileSystemComponent {

public:

    virtual void show(
        int indent = 0
    ) = 0;

    virtual ~FileSystemComponent() {}
};

class File
    : public FileSystemComponent {

private:

    string name;

public:

    File(
        const string& n
    )
        : name(n)
    {}

    void show(
        int indent = 0
    ) override {

        for(int i = 0; i < indent; i++)
            cout << " ";

        cout
            << "File: "
            << name
            << endl;
    }
};

class Folder
    : public FileSystemComponent {

private:

    string name;

    vector<FileSystemComponent*> children;

public:

    Folder(
        const string& n
    )
        : name(n)
    {}

    void add(
        FileSystemComponent* component
    ) {

        children.push_back(
            component
        );
    }

    void show(
        int indent = 0
    ) override {

        for(int i = 0; i < indent; i++)
            cout << " ";

        cout
            << "Folder: "
            << name
            << endl;

        for(auto child : children) {

            child->show(
                indent + 4
            );
        }
    }
};

int main() {

    //
    // FILES
    //

    File* file1 =
        new File("resume.pdf");

    File* file2 =
        new File("photo.png");

    File* file3 =
        new File("song.mp3");

    //
    // FOLDERS
    //

    Folder* documents =
        new Folder("Documents");

    Folder* media =
        new Folder("Media");

    Folder* root =
        new Folder("Root");

    //
    // BUILD TREE
    //

    documents->add(file1);

    media->add(file2);

    media->add(file3);

    root->add(documents);

    root->add(media);

    //
    // DISPLAY
    //

    root->show();

    return 0;
}