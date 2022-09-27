#include "Node.h"
#include <iostream>
#include <fstream>

using namespace std;
#ifndef LIST
#define LIST

class List : public Node{
    public:
        List();
        List(unsigned int _length);
        List(const List &other);
        ~List();
        List& operator=(const List& other);
        int setLength(unsigned int new_length);
        unsigned int getLength();
        int setElement(unsigned int pos, long val);
        long getElement(unsigned int pos) const;

        List operator+(const List&);
        List operator+=(const List&);
        List operator++();
        List operator++(int);
        List operator--();
        List operator--(int);
        friend ostream& operator<<(ostream &, List );
        friend istream& operator>>(istream &, List &);

        unsigned int length;

};  

#endif