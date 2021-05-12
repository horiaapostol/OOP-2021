#include "cstdint"
#include "cmath"

template<class Key>
class Hasher {
public:
    template<class Key>
    uint64_t Hash(Key value);

    template<>
    uint64_t Hash<int>(int value) {
        return ((uint64_t)(value * floor(0.323 * ((uint64_t)1 << 16))) >> 6);
    }
};

template<class FirstType, class SecondType>
class Pair {
public:
    FirstType first;
    SecondType second;
    Pair(FirstType first, SecondType second) :first{ first }, second{ second }{}
};

template<class Type>
class Node {
public:
    Type value;
    Node* next;
};

template<class T, class Link = Node<T>*>
class List {
    using value_type = T;
private:
    Link head, tail;
public:
    List(): tail{ 0 }, head{ 0 }{}
    void add(value_type element) {
        Link temp = new Node<T>;
        temp->value = element;
        temp->next = 0;
        if (head == nullptr) {
            head = tail = temp;
        }
        else {
            tail->next = temp;
            tail = tail->next;
        }
    }
    void erase() {
        while (this->head != nullptr) {
            this->head = this->head->next;
       }
       delete this->head;
       
    }
};

class Iterator {
public:
    int* iterator;
    Iterator& operator++() { 
        iterator++; 
        return *this; 
    }
    bool operator!=(Iterator& it) {
        return iterator != it.iterator;
    }
    int operator*() {
        return *iterator;
    }
};

template<class K, class V, class Hasher = Hasher<K>>
class Map {
    using value_type = V;
    using list = List<Pair<K, V>>;
private:
    list* elemente;
    size_t size;
    Hasher my_hasher;
public:
    Map() 
        : size{ 100 }
    {
        this->elemente = new list[100]{};
    }
    ~Map() {
        delete[] elemente;
    }
    Iterator begin() {
        Iterator it;
        it.iterator = &this->elemente[0];
        return it;
    }
    Iterator end() {
        Iterator it;
        it.iterator = &this->elemente[this->size];
        return it;
    }
   
};
