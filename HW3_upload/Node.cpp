#include <iostream>
#include "Node.h"
using namespace std;

Node::Node(){
    _Node = NULL;
}

Node::Node(unsigned int _length){
    if(_length == 0){
        _Node = NULL;
    }else
    {
        _Node = new long [_length];
    }
}

Node::~Node(){
    if(_Node != 0){
        delete [] _Node;
        _Node = NULL;
    }
}

long* Node::reCreate(unsigned int _length){
    if(_length != 0){
        if(_Node == NULL){
            _Node = new long [_length];
        }else
        {
            delete [] _Node;
            _Node = new long [_length];

        }
    }else
    {
        delete [] _Node;
        _Node = NULL;
    }
    return _Node;
    /*if(_Node == NULL){
        _Node = new long [_length];
    }else
    {
        delete [] _Node;

        _Node = new long [_length];
    }
    return _Node;*/
}