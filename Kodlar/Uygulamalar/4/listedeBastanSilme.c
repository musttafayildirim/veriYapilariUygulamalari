#include <stdlib.h>
#include <iostream>

using namespace std;

struct Bliste
{
	int veri;
	struct Bliste *ileri;
};


struct Bliste* yeni_bliste = NULL;

void dugumEkle(int yeniVeri){
	struct Bliste* yeni_Bliste = (struct Bliste*) malloc(sizeof(struct Bliste));
	yeni_Bliste -> veri = yeniVeri;
	yeni_Bliste -> ileri = yeni_bliste;
	yeni_bliste= yeni_Bliste;
}


void ekranaYaz(){
	struct Bliste* dugumPtr;
	dugumPtr = yeni_bliste;
	while (dugumPtr != NULL){
		cout << dugumPtr-> veri << " ";
		dugumPtr = dugumPtr->ileri;
	}
}


void sil(){
    if(yeni_bliste != NULL){
	struct Bliste* temp = yeni_bliste;
	yeni_bliste = yeni_bliste->ileri;
	free(temp);
	}
    }

int main(){
	dugumEkle(5);
	dugumEkle(12);
	dugumEkle(3);
	dugumEkle(23);
	dugumEkle(4);
	cout << "Tek yonlu bagli liste: ";
	ekranaYaz();
	cout << "\n";
	sil();
	cout << "Tek yonlu bagli liste: (Son Hali) ";
	ekranaYaz();
	cout << "\n";
	return 0;
}
