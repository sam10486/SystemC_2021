#include "List.h"
#include <iostream>
#include <fstream>

using namespace std;


List::List(){
    Node();
    length = 0;
}

List::List(unsigned int _length) : Node(_length){
    length = _length;
}

// copy constructor
List::List(const List &other){
    length = other.length;
    if(length > 0){
        _Node = reCreate(length);
        unsigned int  i;
        for(i = 0; i < length; i++){
          _Node[i] = other.getElement(i);
        }   
    }else
    {
        length = 0;
    }
}

List::~List(){
    delete [] _Node;
    _Node = NULL;
    length = 0;
}
//assingment operator
List& List::operator=(const List& other){
    if(this != &other){
        //delete [] _Node;
        length = other.length;
        if(length > 0){
           _Node = reCreate(length);
           for(unsigned int i = 0; i < length; i++)
                _Node[i] = other._Node[i];  
        }
    }
    return *this;
}
//setLength
int List::setLength(unsigned int new_length){
    if(length == 0){
        length = new_length;
        _Node = reCreate(length);
    }else
    {
        cout << "the length is not 0!" << endl;
    }
    return 0;    
}

unsigned int List::getLength(){
    return length;
}
//setELement
int List::setElement(unsigned int pos, long val){
    if(pos < length && pos >=0){
        _Node[pos] = val;
        return 1;
    }else
    {
        cout << "position error!"
             << endl;
    }
    return 0;
}
//getElement
long List::getElement(unsigned int pos) const{
    if(pos < length && pos >= 0){
        return _Node[pos];
    }else
    {
        cout << "pos is illegal!"
             << endl;
    }
    return -99999;

}

List List::operator+(const List &other){
    unsigned int loop = (length < other.length) ? length : other.length;
    List lt(loop);
    for(unsigned int i = 0; i < loop; i++){
        lt._Node[i] = _Node[i] + other._Node[i];
    } 
    return lt;
}

List List::operator+=(const List &other){
    unsigned int loop = (length < other.length) ? length : other.length;
    for(unsigned int i = 0; i < loop; i++){
        _Node[i] += other._Node[i];
    }
    return *this;
}

//prefix ++
List List::operator++(){
    for(unsigned int i = 0; i < length; i++)
        ++_Node[i];
    return *this;
}

//postfix ++ 
List List::operator++(int){
    List tmp(*this);
    for(unsigned int i = 0; i < length; i++)
        _Node[i]++;
    return tmp;
}

List List::operator--(){
    for(unsigned int i = 0; i < length; i++)
        --_Node[i];
    return *this;
}

List List::operator--(int){
    List tmp(*this);
    for(unsigned int i = 0; i < length; i++)
        _Node[i]--;
    return tmp;
}

ostream& operator<<(ostream &out, List list){
    for(unsigned int i = 0; i < list.length; i++)
        out << list._Node[i] << " ";

    out << endl;
    return out;
}

istream& operator>>(istream &in, List &list){
    for(unsigned int i = 0; i < list.length; i++)
        in >> list._Node[i];
    return in;
}