/**
* @file G191210027
* @description 
* @course 2.Ogretim A grubu
* @assignment 1.Odev
* @date 27.11.2022
* @author Selcan Narin - selcan.narin@ogr.edu.tr
*/
#include "../include/NodeforYonetici.hpp"

NodeforYonetici::NodeforYonetici(SatirListesi* data, NodeforYonetici *next, NodeforYonetici *prev,double average)
{
    this->data=data;
    this->next=next;
    this->prev=prev;
    this->average=average;
}
NodeforYonetici::NodeforYonetici(SatirListesi* data, NodeforYonetici *next, NodeforYonetici *prev)
{
    this->data=data;
    this->next=next;
    this->prev=prev;
    this->average= average;
}
NodeforYonetici::NodeforYonetici(SatirListesi* data, NodeforYonetici *next)
{
    this->data=data;
    this->next=next;
    this->prev=prev;
    this->average= average;
}
NodeforYonetici::NodeforYonetici(SatirListesi* data)
{
    this->data=data;
    this->next=next;
    this->prev=prev;
    this->average= average;
}
NodeforYonetici::NodeforYonetici()
{
    this->data = data;
    this->next = next;
    this->prev = prev;
    this->average = average;
}

//double calculateAverage(){
    //????????
//}