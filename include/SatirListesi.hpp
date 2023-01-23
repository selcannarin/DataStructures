#ifndef SATIRLISTESI_HPP
#define SATIRLISTESI_HPP

#include "Node.hpp"
#include "NoSuchElement.hpp"
#include <iostream>
#include <iomanip>

using namespace std;

class SatirListesi
{
private:
    Node *head;
    int size;

    Node* FindPreviousByPosition(int index)throw (NoSuchElement);

    Node* FindPosition(int index) throw(NoSuchElement);

public:
    SatirListesi();
    ~SatirListesi();
    int Count()const;
    bool isEmpty()const;
    void add(const int& item);
    void insert(int index,const int& item);
    const int& first()throw(NoSuchElement);
    const int& last()throw(NoSuchElement);
    void removeAt(int index)throw(NoSuchElement);
    void clear();  
    double avgOfNodes();
    void displaySatir(int satirNumber);
    void displayDeleteSatir(int satirNumber);
    int getRandomindex();  
};
#endif