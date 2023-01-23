/**
* @file G191210027
* @description 
* @course 2.Ogretim A grubu
* @assignment 1.Odev
* @date 27.11.2022
* @author Selcan Narin - selcan.narin@ogr.edu.tr
*/
#include "../include/SatirListesi.hpp"
#include "../include/YoneticiListesi.hpp"
#include "../include/ReadAndInsert.hpp"
#include "../include/Exception.hpp"

using namespace std;
#include <fstream>
#include <string>
#include <iostream>
#include <sstream>  
#include <cstdlib>
#include <stdlib.h>


int main(int argc, char** argv)
{
    ReadAndInsert* readingFile = new ReadAndInsert("veriler.txt");
    YoneticiListesi* yoneticiListesi = readingFile->AddToYoneticiListesi();
    yoneticiListesi->displayYonetici();

   
    while (true) {

        char choice;
        cin >> choice;
        if (choice == 'd') {
            system("cls");
            if (yoneticiListesi->currentPage == yoneticiListesi->pageTotal) {
                yoneticiListesi->currentPage = 1;
                yoneticiListesi->currentSatir = 1;
                yoneticiListesi->displayYonetici();
            }
            else {
                yoneticiListesi->currentPage++;
                yoneticiListesi->currentSatir = ((yoneticiListesi->currentPage-1)*8)+1;
                yoneticiListesi->displayYonetici();
            }
        }
        if (choice == 'a') {
            system("cls");
            if (yoneticiListesi->currentPage == 1) {
                yoneticiListesi->currentPage = yoneticiListesi->pageTotal;
                yoneticiListesi->currentSatir = yoneticiListesi->size;
                yoneticiListesi->displayYonetici();
            }
            else {
                yoneticiListesi->currentPage--;
                yoneticiListesi->currentSatir = (yoneticiListesi->currentPage * 8);
                yoneticiListesi->displayYonetici();
            }
        }
        if (choice == 'c') {
            system("cls");
            yoneticiListesi->currentSatir++;

            if (yoneticiListesi->currentSatir > yoneticiListesi->size) {//son sayfadayssa ilk sayfaya ge�i� yap�l�yor.
                yoneticiListesi->currentPage = 1;
                yoneticiListesi->currentSatir = 1;
            }
            if (yoneticiListesi->currentSatir > yoneticiListesi->currentPage * 8) //bir sonraki sayfaya ge�i� yapacak.
            {
                    yoneticiListesi->currentPage++;
            }

            yoneticiListesi->displayYonetici();
        }
        if (choice == 'z') {
            system("cls");

            if (yoneticiListesi->currentSatir % 8 == 1)//bir �nceki sayfaya gidecekse
            {
                if (yoneticiListesi->currentPage == 1) {//ilk sayfadaysak
                    yoneticiListesi->currentPage = yoneticiListesi->pageTotal;//son sayfaya ge�i� yap�l�r.
                    yoneticiListesi->currentSatir = yoneticiListesi->size;
                    yoneticiListesi->displayYonetici();
                }
                else {
                    yoneticiListesi->currentPage--;
                    yoneticiListesi->currentSatir--;
                    yoneticiListesi->displayYonetici();
                }
            }

            else {
                yoneticiListesi->currentSatir--; //�nceki sat�r� se�mek i�in
                yoneticiListesi->displayYonetici();
            }

        }

        if (choice == 'p') {
            system("cls");
            yoneticiListesi->RemoveAt(yoneticiListesi->currentSatir - 1);
            yoneticiListesi->currentSatir--;
            yoneticiListesi->displayYonetici();
        }

        if (choice == 'k') {
            system("cls");
            yoneticiListesi->getRandomindex(yoneticiListesi->currentSatir - 1);
            yoneticiListesi->displayYonetici();
            char secondChoice;
            cin >> secondChoice;
            if (secondChoice == 'k') {
                system("cls");
                yoneticiListesi->randomRemoveAtSatirListesi(yoneticiListesi->currentSatir - 1);

                yoneticiListesi->randomSatir = -1;
                yoneticiListesi->displayYonetici();
            }
            else {
                system("cls");
                yoneticiListesi->randomSatir = -1;
                continue;
            }
        }
    }

}



 