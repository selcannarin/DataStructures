#ifndef YONETICILISTESI_HPP
#define YONETICILISTESI_HPP

#include <iostream>
#include <ctime>
#include <iomanip>
#include "SatirListesi.hpp"
#include "NodeforYonetici.hpp"
#include <stdlib.h>     /* rand */
#include "IndexOutOfBounds.hpp"


class YoneticiListesi {
    private:
    
    public:
        int currentPage = 1;
        int pageTotal = 0;
        int currentSatir = 1;
        int randomSatir = -1;
        NodeforYonetici* head;
        int size;

        NodeforYonetici* FindPreviousByPosition(int index)throw (NoSuchElement);

        NodeforYonetici* FindPosition(int indx) throw(NoSuchElement);

    YoneticiListesi();
    ~YoneticiListesi();
    int Count()const;
    bool isEmpty()const;
    void add(SatirListesi*& item);
    void Sortedinsert(int index, SatirListesi*& item)throw(NoSuchElement);
    void getAvg(int);
    void randomRemoveAtSatirListesi(int index)throw(NoSuchElement); //satır listesinden random düğüm silme
    void getRandomindex(int index);
    void RemoveAt(int index);//yönetici düğümü index ile silme
    void clear();

    void writeLine(int adet);

    void displayYonetici();
};
#endif