#ifndef NODE
#define NODE

class Node{
        
    public:
        long *_Node;
        Node();
        Node(unsigned int _length);
        ~Node();
        long* reCreate(unsigned int _length);

};

#endif