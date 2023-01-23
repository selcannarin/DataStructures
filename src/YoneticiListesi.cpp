/**
* @file G191210027
* @description 
* @course 2.Ogretim A grubu
* @assignment 1.Odev
* @date 27.11.2022
* @author Selcan Narin - selcan.narin@ogr.edu.tr
*/
#include "../include/YoneticiListesi.hpp"


NodeforYonetici* YoneticiListesi::FindPreviousByPosition(int index)throw (NoSuchElement) {
    if (index < 0 || index > size) throw NoSuchElement("No Such Element");
    NodeforYonetici* prv = head;
    int i = 1;
    for (NodeforYonetici* itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}

NodeforYonetici* YoneticiListesi::FindPosition(int indx)throw (NoSuchElement) {
    if (indx < 0 || indx > size) throw NoSuchElement("No Such Element");
    return this->FindPreviousByPosition(indx + 1);

}

YoneticiListesi::YoneticiListesi()
{
    head=NULL;
    size=0;
}
void YoneticiListesi::clear() {
    while (!isEmpty())
        RemoveAt(0);
}
YoneticiListesi::~YoneticiListesi()
{
    clear();
}

int YoneticiListesi::Count()const{
     return size;
}

bool YoneticiListesi::isEmpty()const{
    return size == 0;
}

void YoneticiListesi::add(SatirListesi*& item){
    Sortedinsert(size,item);
}


void YoneticiListesi::Sortedinsert(int index, SatirListesi*& item)throw(NoSuchElement) {
	if (index < 0 || index > size) throw ("Index out of Range");
    NodeforYonetici* add = new NodeforYonetici(item);
    add->prev = NULL;
    add->next = NULL;
    add->average=add->data->avgOfNodes();
    if (head == NULL)
    {
        head = add;
       
    }
    else if (add->average < head->average)
    {
        add->next = head;
        head->prev = add;
        head = add;
        
    }
    else
    {
        NodeforYonetici* cur = head;
        NodeforYonetici* temp = new NodeforYonetici();
        while (cur->next != NULL)
        {
            if (add->average < ((cur->next)->average))
            {
                temp = cur->next;
                cur->next = add;
                add->prev = cur;
                add->next = temp;
                (add->next)->prev = add;
                
                break;
            }
            cur = cur->next; 
        }
        cur->next = add;
        add->prev = cur;
       
        
    }
    size++;
}

void YoneticiListesi::randomRemoveAtSatirListesi(int index)throw(NoSuchElement){
    srand(time(NULL));
    int count = this->Count();
    if (index < 0 || index >= count)
        throw("Index out of bounds");
    NodeforYonetici* tmp = FindPreviousByPosition(index + 1);
    int sizeOfSatir = tmp->data->Count();
    if (sizeOfSatir == 1) { //eğer tek eleman kaldıysa direkt düğüm silinir.
        RemoveAt(index);
        currentSatir--;
    }
    else{
        
        tmp->data->removeAt(randomSatir);
        double oldAvg = tmp->average;
        getAvg(index);

        NodeforYonetici* tail = FindPreviousByPosition(size);

        if (head == NULL)
        {
            head = tmp;
            tmp->next = NULL;
            tmp->prev = NULL;
            return;
        }
        if (tmp->data == head->data) { //ortalaması değişen head dir 
            if (tmp->average <= head->next->average) //ortalaması ya azalmıştır ya da aynıdır. Düğümler aynı kalır.
            {
                return;
            }
            else { //ortalaması artmıştır.
                head->next->prev = NULL;
                head = head->next;
                if ((tail->average) <= tmp->average) {//hiçbirinden küçük değil ayni listenin sonuna yerleşecek.                   
                    tail->next = tmp;
                    tmp->prev = tail;
                    tmp->next = NULL;
                }
                else {
                    for (NodeforYonetici* itr = head; itr->next != NULL; itr = itr->next) {

                        if (itr->average >= tmp->average) {//listenin ortalarına yerleşmek için
                            tmp->next = itr;
                            tmp->prev = itr->prev;
                            itr->prev->next = tmp;
                            itr->prev = tmp;
                            break;
                        }
                    }
                }
            }
        }


        else if (tail->data == tmp->data) {//son düğümse yeri değişecek olan
            if ((tmp->average) >= oldAvg) {
                //hiçbirinden küçük değil ayni listenin sonuna yerleşecek.
                return;
            }
            else {
                tmp->prev->next = NULL; //yeni tail
                if (tmp->average <= head->average) { //eğer ilk düğümden küçükse yeni head olur
                    head->prev = tmp;
                    tmp->next = head;
                    tmp->prev = NULL;
                    head = tmp;
                }
                else { //ortalara yerleşmek için
                    for (NodeforYonetici* itr = head; itr->next != NULL; itr = itr->next) { //

                        if (itr->average >= tmp->average) {
                            tmp->next = itr;
                            tmp->prev = itr->prev;
                            itr->prev->next = tmp;
                            itr->prev = tmp;
                            break;
                        }
                    }
                }

            }
        }
        else { //ortalardan olan bir düğümün yeri değişecek.
            tmp->prev->next = tmp->next; //düğümü aradan çıkarıyorum.
            tmp->next->prev = tmp->prev;
            for (NodeforYonetici* itr = head; itr->next != NULL; itr = itr->next) {
                if (tmp->average <= head->average) { //eğer ilk düğümden küçükse yeni head olur
                    head->prev = tmp;
                    tmp->next = head;
                    tmp->prev = NULL;
                    head = tmp;
                    break;
                }
                if ((tail->average) <= tmp->average) {
                    //hiçbirinden küçük değil ayni listenin sonuna yerleşecek.
                    tail->next = tmp;
                    tmp->prev = tail;
                    tmp->next = NULL;
                    break;
                }
                if (itr->average >= tmp->average) { //araya yerleşecek.
                    tmp->next = itr;
                    tmp->prev = itr->prev;
                    itr->prev->next = tmp;
                    itr->prev = tmp;
                    break;
                }
            }
        }
    }
  
}
    

void YoneticiListesi::getRandomindex(int index) {
   
        NodeforYonetici* tmp = FindPreviousByPosition(index + 1);
        randomSatir = tmp->data->getRandomindex();
        
}

void YoneticiListesi::RemoveAt(int index)
{
    if (index < 0 || index >= size) return; //verilen index uyumsuz ise
    NodeforYonetici* del;//silinecek düğümü tutması için geçici
    if (index == 0) { //silinecek düğüm head ise
        del = head;
        if (size == 1) head = NULL; //Eğer sadece head varsa o null olur.
        else {
            head = head->next;
            if (head != NULL) head->prev = NULL;
         
        }

    }
    else if (index == (size - 1)) { //son düğüm silinecekse
        NodeforYonetici* prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = NULL;
        if (currentSatir % 8 == 1) {//eğer son sayfada bir eleman kaldıysa sayfanın silinmesi gerekir.
            pageTotal--;
            currentPage--;            
        }
    }
    else {
        NodeforYonetici* prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        del->next->prev = prv;
    }
    size--;
    delete del; //geçici düğüm bellekten silindi.
}

void YoneticiListesi::getAvg(int index) {

	NodeforYonetici* yNode = this->FindPreviousByPosition(index+1);
	if (index < 0 || index >= size) throw NoSuchElement("No Such Element"); //index 0 dan küçük veya düğüm sayısından büyük
	if (yNode == NULL) throw "hata";
	if (yNode->data->isEmpty()) { yNode->average = 0; return; }
	yNode->average = yNode->data->avgOfNodes();

    
}

void YoneticiListesi::writeLine(int adet) {
    for (int i = 0;i < adet;i++) {
        cout << "---------  ";
    }
    cout << endl;
}
void YoneticiListesi::displayYonetici() {
 
    NodeforYonetici* itr;
    int i = 0;
    if (size % 8 == 0) pageTotal = size / 8;
    else pageTotal = (size / 8) + 1;

    if (currentPage == pageTotal ) { //eğer son sayfaysa 
        cout << "<----       " << setw(80) << "son" << endl;
        i = (currentPage - 1) * 8;
        for (itr = FindPosition((currentPage - 1) * 8);i < size && itr!= NULL;itr = itr->next, i++) {
            cout << setw(9) << itr<<"  ";
        }
        cout << endl;
        writeLine(size- ((currentPage - 1) * 8));
        i = (currentPage - 1) * 8;
        for (itr = FindPosition((currentPage - 1) * 8);i < size && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) << itr->prev<<"  ";
        }
        cout << endl;
        i = (currentPage - 1) * 8;
        writeLine(size - ((currentPage - 1) * 8));
        for (itr = FindPosition((currentPage - 1) * 8);i < size && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) <<  itr->average << "  ";
        }
        cout << endl;
        i = (currentPage - 1) * 8;
        writeLine(size - ((currentPage - 1) * 8));
        for (itr = FindPosition((currentPage - 1) * 8);i < size && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) <<itr->next << "  ";
        } 
        cout << endl;
       
        writeLine(size - ((currentPage - 1) * 8));

        itr = this->FindPosition(currentSatir - 1);
        if (randomSatir != -1) { //eğer random silme işlemi gerçekleştiyse
            if (currentPage == 1) //eğer birinci sayfadaysak direkt satır numarasına göre işlem yaparız.
                itr->data->displayDeleteSatir(currentSatir);
            else {
                if (currentSatir % 8 == 0) { //8.satır ve katları için
                    itr->data->displayDeleteSatir(8);
                }
                else
                    itr->data->displayDeleteSatir(currentSatir % 8); // 8.satır olmayanlar için moduna göre satır numarası seçilir.
            }
        }
        else
        {
            if (currentPage == 1) //eğer birinci sayfadaysak direkt satır numarasına göre işlem yaparız.
                itr->data->displaySatir(currentSatir);
            else {
                if (currentSatir % 8 == 0) { //8.satır ve katları için
                    itr->data->displaySatir(8);
                }
                else
                    itr->data->displaySatir(currentSatir % 8); // 8.satır olmayanlar için moduna göre satır numarası seçilir.
            }
        }
    }
    else {
        if (currentPage == 1) {
            cout << "ilk   " << setw(80) << "----->" << endl;
        }
        else
            cout << "<-----" << setw(80) << "----->" << endl;
        i = 0;
        for (itr = FindPosition((currentPage - 1) * 8);i < 8 && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) << itr << "  ";
        }
        cout << endl;
        writeLine(8);
        
        i = 0;
        for (itr = FindPosition((currentPage - 1) * 8);i < 8 && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) << itr->prev << "  ";
        }
        cout << endl;
        writeLine(8);
       
        i = 0;
        for (itr = FindPosition((currentPage - 1) * 8);i < 8 && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) << itr->average << "  ";
        } 
        cout << endl;
        writeLine(8);
     
        i = 0;
        for (itr = FindPosition((currentPage - 1) * 8);i < 8 && itr != NULL;itr = itr->next, i++) {
            cout << setw(9) << itr->next << "  ";
        }
        cout << endl;
        writeLine(8);

        itr = this->FindPosition(currentSatir - 1);
        if (randomSatir != -1) {
            if (currentPage == 1) //eğer birinci sayfadaysak direkt satır numarasına göre işlem yaparız.
                itr->data->displayDeleteSatir(currentSatir);
            else {
                if (currentSatir % 8 == 0) { //8.satır ve katları için
                    itr->data->displayDeleteSatir(8);
                }
                else
                    itr->data->displayDeleteSatir(currentSatir % 8); // 8.satır olmayanlar için moduna göre satır numarası seçilir.
            }
        }
        else {
            if (currentPage == 1) //eğer birinci sayfadaysak direkt satır numarasına göre işlem yaparız.
                itr->data->displaySatir(currentSatir);
            else {
                if (currentSatir % 8 == 0) { //8.satır ve katları için
                    itr->data->displaySatir(8);
                }
                else
                    itr->data->displaySatir(currentSatir % 8); // 8.satır olmayanlar için moduna göre satır numarası seçilir.
            }
        }
        
                 
    }
    
}