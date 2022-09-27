#ifndef LIST
#define LIST

#include <iostream>
#include <assert.h>
#include "Node.h"

using namespace std;

template <class T>
class List;
template <class T>
ostream& operator<<(ostream &, List<T>);
template <class T>
istream& operator>>(istream &, List<T>&);


template <class T>
class List : public Node<T> {
private:
    unsigned int length;

public:
    List();
    List(unsigned int _length);
    List(const List &other);
    ~List();
    // overloading operators
    List& operator=(const List &);
    inline bool operator==(const List&);
    friend ostream& operator<< <T>(ostream &, List<T>);
    friend istream& operator>> <T>(istream &, List<T>&);
    List operator+(const List &);
    List operator+=(const List &);
    List operator++();
    List operator++(int);
    List operator--();
    List operator--(int);

    int setLength(unsigned int new_length);
    unsigned int getLength();
    int setElement(unsigned int pos, T val) ;
    T getElement(unsigned int pos) const;
};

//intial 
template <class T>
List<T>::List() : Node<T>() {
    length = 0;
}
//initial length
template <class T>
List<T>::List(unsigned int _length) : Node<T>(_length) {
    length = _length;
    if (length == 0)
        this->_Node = NULL;
    else {
        assert(this->_Node != NULL);
    }
}
//copy constructor
template <class T>
List<T>::List(const List &other) : Node<T>(other.length) {
    length = other.length;
    for (unsigned int i = 0; i < length; i++)
        setElement(i, other.getElement(i));
}

//delete
template <class T>
List<T>::~List() {
    if (length == 0)
        assert(this->_Node == NULL);
    else {
        length = 0;
    }
}

//assignment operator
template <class T>
List<T>& List<T>::operator=(const List<T> &other) {
    if (this != &other) {
        this->reCreate(0);
        length = other.length;
        if (length != 0) {
            this->reCreate(length);
            assert(this->_Node != NULL);
            for (unsigned int i = 0; i < length; i++)
                setElement(i, other.getElement(i));
        }
    }
    return *this;
}

//equal
template <class T>
inline bool List<T>::operator==(const List<T> &r) {
    if (this == &r)
        return true;
    if (this->length != r.length)
        return false;
    for (unsigned int i = 0; i < this->length; i++) {
        if (this->getElement(i) != r.getElement(i))
            return false;
    }
    return true;
}

// >>
template <class T>
istream& operator>>(istream &in, List<T> &list) {
    for (unsigned int i = 0; i < list.length; i++){
        T val;
        in >> val;
        list.setElement(i, val);

    }
        

    return in;
}

// <<
template <class T>
ostream& operator<<(ostream &out, List<T> list) {
    for (unsigned int i = 0; i < list.length; i++)
        out << list.getElement(i) << " ";
    out << endl;

    return out;
}
//setlength
template <class T>
int List<T>::setLength(unsigned int _length) {
    if (length == 0) {
        length = _length;
        this->reCreate(length);
        assert(this->_Node != NULL);
        return 1;
    } else {
        cerr << "List is not empty, cannot set length\n";
        return 0;
    }
}

//getlength
template <class T>
unsigned int List<T>::getLength() {
    return length;
}

//setelement
template <class T>
int List<T>::setElement(unsigned int pos, T val) {
    if (pos >= length) {
        cerr << "Given position is larger than the list size\n";
        return 0;
    } else {
        this->_Node[pos] = val;
        return 1;
    }
}

//getelement
template <class T>
T List<T>::getElement(unsigned int pos) const{
    if (pos >= length) {
        cerr << "Given position is larger than the list size\n";
        return 0;
    } else
        return this->_Node[pos];
}

// operator+
template <class T>
List<T> List<T>::operator+(const List<T> &other) {
    unsigned int loop = length < other.length ? length:other.length;
    List list(loop);

    for (unsigned int i = 0; i < loop; i++) {
        list.setElement(i, (this->getElement(i) + other.getElement(i)));
    }
    return list;
}

//operator +=
template <class T>
List<T> List<T>::operator+=(const List<T> &other) {
    unsigned int loop = length < other.length ? length:other.length;

    for (unsigned int i = 0; i < loop; i++) {
        this->_Node[i] += other._Node[i];
    }
    return *this;
}

//operator ++a
template <class T>
List<T> List<T>::operator++() {
    for (unsigned int i = 0; i < length; i++) {
        ++this->_Node[i];
    }
    return *this;
}

//operator a++
template <class T>
List<T> List<T>::operator++(int) {
    List tmp(*this);
    for (unsigned int i = 0; i < tmp.length; i++) {
        this->_Node[i]++;
    }
    return tmp;
}

//operator --a
template <class T>
List<T> List<T>::operator--() {
    for (unsigned int i = 0; i < length; i++) {
        --this->_Node[i];
    }
    return *this;
}

//operator a--
template <class T>
List<T> List<T>::operator--(int) {
    List tmp(*this);
    for (unsigned int i = 0; i < length; i++) {
        this->_Node[i]--;
    }
    return tmp;
}


#endif
