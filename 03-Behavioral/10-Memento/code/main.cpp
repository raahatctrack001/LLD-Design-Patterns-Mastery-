#include<iostream>
#include<vector>

using namespace std;


/*
===========================================================
MEMENTO DESIGN PATTERN
===========================================================

REAL WORLD EXAMPLE:
-------------------

GitHub Version Control System

We want to support:
- commit history
- undo (revert commit)
- restore previous versions
- track file changes

PROBLEM:
--------
We need to save snapshots of repository state
WITHOUT exposing internal structure.

SOLUTION:
---------
Use Memento Pattern:
- GitRepo = Originator
- Commit = Memento
- GitHistory = Caretaker

===========================================================
*/




/*
===========================================================
MEMENTO (SNAPSHOT)
===========================================================
*/

class Commit {

private:

    string codeSnapshot;
    string message;

public:

    Commit(
        string code,
        string msg
    )
        : codeSnapshot(code),
          message(msg)
    {}

    string getCode() {

        return codeSnapshot;
    }

    string getMessage() {

        return message;
    }
};




/*
===========================================================
ORIGINATOR (GITHUB REPO)
===========================================================
*/

class GitRepo {

private:

    string codeBase;

public:

    void writeCode(
        const string& code
    ) {

        codeBase = code;
    }

    string getCode() {

        return codeBase;
    }



    /*
    CREATE SNAPSHOT
    */

    Commit save(
        const string& message
    ) {

        return Commit(codeBase, message);
    }



    /*
    RESTORE SNAPSHOT
    */

    void restore(
        Commit commit
    ) {

        codeBase = commit.getCode();
    }
};




/*
===========================================================
CARETAKER (HISTORY MANAGER)
===========================================================
*/

class GitHistory {

private:

    vector<Commit> history;

public:

    void push(
        Commit commit
    ) {

        history.push_back(commit);
    }

    Commit pop() {

        Commit last = history.back();

        history.pop_back();

        return last;
    }

    void showHistory() {

        cout << "Commit History:\n";

        for(auto& c : history) {

            cout
                << "- "
                << c.getMessage()
                << endl;
        }
    }
};




/*
===========================================================
CLIENT
===========================================================
*/

int main() {

    GitRepo repo;
    GitHistory history;


    repo.writeCode("Initial commit: Hello World");
    history.push(repo.save("Init commit"));

    repo.writeCode("Added login feature");
    history.push(repo.save("Added login"));

    repo.writeCode("Fixed bugs in login");
    history.push(repo.save("Bug fixes"));



    cout << "Current Code:\n";
    cout << repo.getCode() << endl << endl;



    history.showHistory();

    cout << "\n--- Undo last commit ---\n\n";

    repo.restore(history.pop());

    cout << "After rollback:\n";
    cout << repo.getCode() << endl;

    return 0;
}