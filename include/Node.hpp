#ifndef NODE_HPP
#define NODE_HPP

#include <iostream>
using namespace std;

class Node {
public:
    int data;
    Node *next;
    Node *prev;

    Node(const int data, Node *next, Node *prev);
    Node(const int data, Node *next);
    Node(const int data);
};



#endif