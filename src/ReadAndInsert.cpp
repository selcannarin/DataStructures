/**
* @file G191210027
* @description 
* @course 2.Ogretim A grubu
* @assignment 2.Odev
* @date 25.12.2022
* @author Selcan Narin - selcan.narin@sakarya.ogr.edu.tr
*/
#include "../include/ReadAndInsert.hpp"


YoneticiListesi*  ReadAndInsert::AddToYoneticiListesi() {
    readline();
    YoneticiListesi *tmp = new YoneticiListesi();
    int sizee = lineCount();
    for (int i = 0;i < sizee;++i) {
        tmp->add(this->lines[i]);
    }
    return tmp;

} 

ReadAndInsert::ReadAndInsert(std::string fileName){
    this->fileName=fileName;

    int satirlines = lineCount();
    this->lines = new SatirListesi*[satirlines];
    for (int i = 0; i < satirlines; i++) {
        this->lines[i] = new SatirListesi();
    }
}


int ReadAndInsert::lineCount() {
    int counter = 0;
    ifstream file(this->fileName);
    string line;
    while (getline(file, line)){
        ++counter;
    }
    file.close();
    return counter;
}

void ReadAndInsert::readline(){
    string token;
    ifstream file(this->fileName);
    string str;
    int index=0;
    if(!file) {
     cout << "Okuma amaçlı dosya açma hatası!" << endl;
     exit(1);
    }

    
      while (getline(file, token)) {
        istringstream ss(token);

        while (getline(ss, str, ' ')) {
            this->lines[index]->add(stoi(str));
        }
        
        index++;

      }
    file.close();
}




ReadAndInsert::~ReadAndInsert()
{
    if (lines != 0) {
        int count = lineCount();
        for (int i = 0; i < count; i++) {
            if (lines[i] != 0) delete lines[i];
        }
        delete[] lines;
    }
}
