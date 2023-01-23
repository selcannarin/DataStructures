#ifndef READANDINSERT_HPP
#define READANDINSERT_HPP

#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
#include "../include/YoneticiListesi.hpp"

class ReadAndInsert {
private:
    std::string fileName;
    int lineCount();//for size of YoneticiListesi
    SatirListesi** lines;
    void readline();

public:
    ReadAndInsert(std::string fileName);

    ~ReadAndInsert();



    YoneticiListesi* AddToYoneticiListesi();

};


#endif