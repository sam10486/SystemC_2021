#include <iostream>
#include <assert.h>

#ifndef NODE
#define NODE

template <class T>
class Node {
protected:
    T *_Node;

public:
    Node();
    Node(unsigned int _length);
    ~Node();
    T* reCreate(unsigned int _length);
};

template <class T>
Node<T>::Node() {
    _Node = NULL;
}

template <class T>
Node<T>::Node(unsigned int _length) {
    if (_length == 0)
        _Node = NULL;
    else {
        _Node = new T[_length];
        assert(_Node != NULL);
    }
}

template <class T>
Node<T>::~Node() {
    if (_Node != NULL) {
        delete [] _Node;
        _Node = NULL;
    }
}


template <class T>
T* Node<T>::reCreate(unsigned int _length) {
    if (_Node != NULL) {
       delete [] _Node;
       _Node = NULL;
    }
    if (_length == 0)
        _Node = NULL;
    else {
        _Node = new T[_length];
        assert(_Node != NULL);
    }
    return _Node;
}



#endif