/**
* @file G191210027
* @description 
* @course 2.Ogretim A grubu
* @assignment 1.Odev
* @date 27.11.2022
* @author Selcan Narin - selcan.narin@ogr.edu.tr
*/
#include "../include/Node.hpp"

Node::Node(const int data, Node *next , Node *prev ) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
Node::Node(const int data, Node *next) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}
Node::Node(const int data) {
    this->data = data;
    this->next = next;
    this->prev = prev;
}