#ifndef NODEFORYONETICI_HPP
#define NODEFORYONETICI_HPP

#include "SatirListesi.hpp"


class NodeforYonetici {
    public:
    SatirListesi *data;//satır listesindeki düğümlerdeki verileri gösteren pointer
    double average;
    NodeforYonetici *next;
    NodeforYonetici *prev;

    NodeforYonetici(SatirListesi* data, NodeforYonetici *next, NodeforYonetici *prev,double average);
    NodeforYonetici(SatirListesi* data, NodeforYonetici *next, NodeforYonetici *prev);//kurucu fonksiyonlar
    NodeforYonetici(SatirListesi* data, NodeforYonetici *next);
    NodeforYonetici(SatirListesi* data);
    NodeforYonetici();
   // double calculateAverage(); //ortalama
};

#endif