/**
* @file G191210027
* @description 
* @course 2.Ogretim A grubu
* @assignment 1.Odev
* @date 27.11.2022
* @author Selcan Narin - selcan.narin@ogr.edu.tr
*/
#include "../include/SatirListesi.hpp"

Node* SatirListesi:: FindPreviousByPosition (int index) throw (NoSuchElement){
 if (index < 0 || index > size) throw NoSuchElement("No Such Element"); //index 0 dan küçük veya düğüm sayısından büyük
    Node *prv = head;
    int i = 1;
    for (Node*itr = head; itr->next != NULL && i != index; itr = itr->next, i++) {
        prv = prv->next;
    }
    return prv;
}
Node* SatirListesi::FindPosition(int index)throw (NoSuchElement) {
    if (index < 0 || index > size) throw NoSuchElement("No Such Element");
    if (index == size) {
        last();
    }
    else
        return this->FindPreviousByPosition(index + 1);

}

SatirListesi::SatirListesi(){
   head = NULL; //başta head boş, eleman yok
   size = 0; 
}

int SatirListesi::Count()const{
    return size;
}

bool SatirListesi::isEmpty()const{
    return size == 0;
}

void SatirListesi::add(const int& item){
    insert(size,item);
}

void SatirListesi::insert(int index, const int& item){
    if(index < 0 || index > size) throw "Index out of Range";
			if(index == 0){//başa ekleme
				if(size == 0){ //düğüm yoksa ilk ekleme
					head = new Node(item,head);
					head->next=head->prev=head;
				}
				else{ //düğüm varken başa ekleme
					head = new Node(item,head,head->prev);
					head->next->prev = head;
					head->prev->next = head; 
				}
			}
			else{//baş hariç bir indexe ekleme
				Node *prv = FindPreviousByPosition(index);
				prv->next = new Node(item,prv->next,prv);
				prv->next->next->prev = prv->next;
			}
			size++;       
}

const int& SatirListesi::first()throw(NoSuchElement){
    if(isEmpty()) throw NoSuchElement("No Such Element");
    return head->data;
}

const int& SatirListesi::last()throw(NoSuchElement){
	if(isEmpty()) throw NoSuchElement("No Such Element");
	return head->prev->data;
}


void SatirListesi::removeAt(int index)throw(NoSuchElement){
    if(index<0 || index >= size) throw NoSuchElement("No Such Element"); //verilen index uyumsuz ise
    Node *del;//silinecek düğümü tutması için geçici
    if(index == 0){ //silinecek düğüm head ise
        del=head;
        if(size == 1) head=NULL; //Eğer sadece head varsa o null olur.
        else{
            head = head->next;
            head->prev = del->prev;
            del->prev->next = head;
        }

    }
    else{
        Node *prv = FindPreviousByPosition(index);
        del = prv->next;
        prv->next = del->next;
        del->next->prev=prv;
    }
    size--;
    delete del; //geçici düğüm bellekten silindi.

}

void SatirListesi::clear(){
    while(!isEmpty())
	removeAt(0);
}

SatirListesi::~SatirListesi(){ //Yıkıcı fonk.
    clear();
}

    double SatirListesi::avgOfNodes() {
    double toplam = 0;
    double ort = 0;
    int i = 0;
    for (Node* itr = head;i < size;itr = itr->next, i++) {
        toplam +=(itr->data);
    }
    ort = toplam / size;
    return ort;
    }

    void SatirListesi::displaySatir(int satirNumber)
    {  
        int i = 0;
       
        
            if (satirNumber > 1) {
                cout << setw(11 * (satirNumber - 1)) << "  " << "*********" << endl;
                for (Node* itr = head;i < size;itr = itr->next, i++) {
                    cout << setw(11 * (satirNumber - 1)) << " " << itr << endl;
                    cout << setw(11 * (satirNumber - 1)) << " " << "---------" << endl;
                    cout << setw(11 * (satirNumber - 1)) << " " << itr->data << endl;
                    cout << setw(11 * (satirNumber - 1)) << " " << "---------" << endl;
                    cout << setw(11 * (satirNumber - 1)) << " " << itr->next << endl;
                    cout << setw(11 * (satirNumber - 1)) << " " << "---------" << endl << "\n";
                }

            }
            else {
                cout << "" << setw(9 * (satirNumber)) << "*********" << endl;
                for (Node* itr = head;i < size;itr = itr->next, i++) {
                    cout << "" << setw(9 * (satirNumber)) << itr << endl;
                    cout << "" << setw(9 * (satirNumber)) << "---------  " << endl;
                    cout << "" << setw(9 * (satirNumber)) << itr->data << endl;
                    cout << "" << setw(9 * (satirNumber)) << "---------  " << endl;
                    cout << "" << setw(9 * (satirNumber)) << itr->next << endl;
                    cout << "" << setw(9 * (satirNumber)) << "---------  " << endl << "\n";
                }

            }
        
        
    }
    void SatirListesi::displayDeleteSatir(int satirNumber) //silinecek düğümü seçerken kullanılır.
    {
        int randomindex = getRandomindex();
        int i = 0;
       
        if (satirNumber > 1) {
            
            cout << setw(11 * (satirNumber - 1)) << "  " << " *********" << endl;
            for (Node* itr = head;i < size;itr = itr->next, i++) {
                cout << setw(11 * (satirNumber - 1)) << " " << itr << endl;
                cout << setw(11 * (satirNumber - 1)) << " " << "---------" << endl;
                cout << setw(11 * (satirNumber - 1)) << " " << itr->data << endl;
                if (randomindex == i) {
                    cout << setw(11 * (satirNumber - 1)) << " " << "---------";
                    cout << "    <---------- Silinecek secili"<<endl;
                }
                else
                    cout << setw(11 * (satirNumber - 1)) << " " << "---------" << endl;
                cout << setw(11 * (satirNumber - 1)) << " " << itr->next << endl;
                cout << setw(11 * (satirNumber - 1)) << " " << "---------" << endl << "\n";
            }

        }
        else {
            
            cout << "" << setw(9 * (satirNumber)) << "*********" << endl;
            for (Node* itr = head;i < size;itr = itr->next, i++) {
                cout << "" << setw(9 * (satirNumber)) << itr << endl;
                cout << "" << setw(9 * (satirNumber)) << "---------  " << endl;
                cout << "" << setw(9 * (satirNumber)) << itr->data << endl;
                if (randomindex == i) {
                    cout << setw(11 * (satirNumber - 1)) << "" << "---------";
                    cout << "    <---------- Silinecek secili" << endl;
                }
                else
                    cout << "" << setw(9 * (satirNumber)) << "---------  " << endl;
                cout << "" << setw(9 * (satirNumber)) << itr->next << endl;
                cout << "" << setw(9 * (satirNumber)) << "---------  " << endl << "\n";
            }

        }


    }
    
    int SatirListesi::getRandomindex() {

        srand(time(NULL));
        int randomSatirindex = 0 + rand() % (size - 0);

        return randomSatirindex;
    }