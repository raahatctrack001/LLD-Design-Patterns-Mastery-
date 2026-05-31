#include<iostream>
#include<vector>
#include<list>
#include<string>

using namespace std;


/*
===========================================================
ITERATOR DESIGN PATTERN
===========================================================

Goal:
-----
Provide a common way to iterate over
different container types without exposing
their internal structure.

Containers:
-----------
1. Vector
2. List
3. Array

===========================================================
*/



/*
===========================================================
ITERATOR INTERFACE
===========================================================
*/

template<typename T>
class Iterator {

public:

    virtual bool hasNext() = 0;

    virtual T next() = 0;

    virtual ~Iterator() {}
};




/*
===========================================================
COLLECTION INTERFACE
===========================================================
*/

template<typename T>
class Collection {

public:

    virtual Iterator<T>* createIterator() = 0;

    virtual ~Collection() {}
};




/*
===========================================================
VECTOR ITERATOR
===========================================================
*/

template<typename T>
class VectorIterator
    : public Iterator<T> {

private:

    vector<T>& data;

    int index;

public:

    VectorIterator(
        vector<T>& data
    )
        :
        data(data),
        index(0)
    {}



    bool hasNext() override {

        return index < data.size();
    }



    T next() override {

        return data[index++];
    }
};




/*
===========================================================
VECTOR COLLECTION
===========================================================
*/

template<typename T>
class VectorCollection
    : public Collection<T> {

private:

    vector<T> data;

public:

    void add(T value) {

        data.push_back(value);
    }



    Iterator<T>* createIterator() override {

        return new VectorIterator<T>(data);
    }
};




/*
===========================================================
LIST ITERATOR
===========================================================
*/

template<typename T>
class ListIterator
    : public Iterator<T> {

private:

    list<T>& data;

    typename list<T>::iterator current;

    typename list<T>::iterator end;

public:

    ListIterator(
        list<T>& data
    )
        :
        data(data)
    {

        current = this->data.begin();

        end = this->data.end();
    }



    bool hasNext() override {

        return current != end;
    }



    T next() override {

        return *current++;
    }
};




/*
===========================================================
LIST COLLECTION
===========================================================
*/

template<typename T>
class ListCollection
    : public Collection<T> {

private:

    list<T> data;

public:

    void add(T value) {

        data.push_back(value);
    }



    Iterator<T>* createIterator() override {

        return new ListIterator<T>(data);
    }
};




/*
===========================================================
ARRAY ITERATOR
===========================================================
*/

template<typename T>
class ArrayIterator
    : public Iterator<T> {

private:

    T* arr;

    int size;

    int index;

public:

    ArrayIterator(
        T* arr,
        int size
    )
        :
        arr(arr),
        size(size),
        index(0)
    {}



    bool hasNext() override {

        return index < size;
    }



    T next() override {

        return arr[index++];
    }
};




/*
===========================================================
ARRAY COLLECTION
===========================================================
*/

template<typename T>
class ArrayCollection
    : public Collection<T> {

private:

    T arr[100];

    int size;

public:

    ArrayCollection()
        :
        size(0)
    {}



    void add(T value) {

        arr[size++] = value;
    }



    Iterator<T>* createIterator() override {

        return new ArrayIterator<T>(
            arr,
            size
        );
    }
};




/*
===========================================================
CLIENT UTILITY FUNCTION
===========================================================
*/

template<typename T>
void printCollection(
    Collection<T>* collection
) {

    Iterator<T>* iterator =
        collection->createIterator();

    while(iterator->hasNext()) {

        cout
            << iterator->next()
            << " ";
    }

    cout << endl;

    delete iterator;
}




/*
===========================================================
CLIENT
===========================================================
*/

int main() {


    /*
    =======================================================
    VECTOR
    =======================================================
    */

    VectorCollection<int> vectorCollection;

    vectorCollection.add(10);
    vectorCollection.add(20);
    vectorCollection.add(30);

    cout
        << "Vector Collection: ";

    printCollection(
        &vectorCollection
    );




    /*
    =======================================================
    LIST
    =======================================================
    */

    ListCollection<string> listCollection;

    listCollection.add("Rahaat");
    listCollection.add("Ali");
    listCollection.add("Aman");

    cout
        << "List Collection: ";

    printCollection(
        &listCollection
    );




    /*
    =======================================================
    ARRAY
    =======================================================
    */

    ArrayCollection<double> arrayCollection;

    arrayCollection.add(1.1);
    arrayCollection.add(2.2);
    arrayCollection.add(3.3);

    cout
        << "Array Collection: ";

    printCollection(
        &arrayCollection
    );



    return 0;
}