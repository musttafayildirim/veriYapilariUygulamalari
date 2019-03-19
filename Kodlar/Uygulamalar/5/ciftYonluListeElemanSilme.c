#include <stdio.h>
#include <stdlib.h>
#include <iostream>
//#include "Header2.h"
using namespace std;
struct dugum{
	int veri;
	dugum *birsonraki;
	dugum *bironceki;
};
//Cift Yonlu Bagli Listeye Sirali Eleman Ekleme
dugum * siralielemanekle(dugum * kontrol, int deger) {
	/*Iki Yonlu Bagli liste bossa. Tek Yonlu Bagli listeden farkli olarak
	kontrol->birsonraki = NULL; ifadesi NULL'u gosteriyordu, birde
	yeni eklenen kontrol->bironceki=NULL'u gosterecek.
*/
	if (kontrol == NULL) {
		kontrol = (dugum *)malloc(sizeof(dugum));
		kontrol->birsonraki = NULL;
		kontrol->bironceki = NULL;
		kontrol->veri = deger;
		return kontrol;
	}

	/*Iki Yonlu Bagli liste dolu ve eklenecek veri ilk elemandan kucukse
	Bu durumda "kok" degisiyor. Burada farklı olarak ilerle diye bir isaretci
	kullanildi, bu isaretci liste sonuna gitti ve yeni eklenen dugumun adresine
	kuyruktaki yani en son dugumun adresine esitledi.*/
	if (kontrol->veri > deger) {
		dugum *gecici = (dugum *)malloc(sizeof(dugum));
		gecici->veri = deger;
		gecici->birsonraki = kontrol;
		kontrol->bironceki = gecici;
		return gecici;
	}
/*E�er eklenecek eleman arada biryerde ise ilerle pointeri tanimlanir. 
Bu pointer dugumlerde gezerek yeni eklenecek eleman�n yerini bulacak.*/
		dugum *ilerle = kontrol;
		while (ilerle->birsonraki != NULL && ilerle->birsonraki->veri < deger){
			ilerle = ilerle->birsonraki;
		}

	/*eklenmek istenen deger dugum degerinden buyukse ve kok'den farkli iken.
	Bu durumda listenin sonraki dugum arasına eleman ekleme. Buradaki ekleme
	islemleri tek yonlu bagli liste ile aynı olmaktadır.*/
	dugum * gecici = (dugum *)malloc(sizeof(dugum));
	gecici->birsonraki = ilerle->birsonraki;
	ilerle->birsonraki = gecici;
	gecici->bironceki = ilerle;
/*Bu kontrol iki yonlu bali listenin sonuna eleman eklendigi icin koyuldu.
En sona eleman eklemede iki tane bag var. Bunlardan biri NULL yapildi,
digeri ise yine kendini gosterecek sekilde baglanir*/
	if (gecici->birsonraki != NULL)
		gecici->birsonraki->bironceki = gecici;
	gecici->veri = deger;
	return kontrol;
}

/*Iki Yonlu Bagli Listeyi Yazd�rma
Buradaki islemlerde Dairesel Listede oldugu gibidir.*/
void yazdir(dugum * kontrol) {
	dugum * ilerle = kontrol;
	int i = 2;
	/*While dongusune hic girmeyecegi icin ilk dugum yazdirilir
	ilerle bir sonraki duume gecer ve program while dongusune girer.*/
	cout << 1 << ". Elemanin Verisi:" << ilerle->veri << endl;
	ilerle = ilerle->birsonraki;
	/*ilerle isaretcisi, kok isaretcisine esit olana kadar butun
	listeyi dolasir.*/
	while (ilerle != NULL) {
		cout << i << ". Elemanin Verisi:" << ilerle->veri << endl;
		ilerle = ilerle->birsonraki;
		i++;
	}

}


dugum * sil(dugum * kontrol, int deger){
    dugum * gecici;
    dugum * ilerle = kontrol ;
    if(kontrol->veri == deger){
        gecici =kontrol;
        kontrol = kontrol ->birsonraki;
        free(gecici);
        return kontrol;
    }
    while (ilerle -> birsonraki != NULL && ilerle -> birsonraki -> veri != deger){
        ilerle = ilerle -> birsonraki;
    }
    if(ilerle -> birsonraki == NULL){
        cout << "Sayi bulunamadi" << endl;
        return kontrol;
    }
    gecici = ilerle -> birsonraki;
    ilerle -> birsonraki = ilerle -> birsonraki -> birsonraki;
    if(ilerle ->  birsonraki != NULL)
        ilerle -> birsonraki -> bironceki = ilerle;
    free(gecici);
    return kontrol;
}



int main() {
	int secim;
	dugum * kok;
	cout << "Cift Yonlu Bagli Liste" << endl;
		kok = NULL;
		kok = siralielemanekle(kok, 100);
		kok = siralielemanekle(kok, 10);
		kok = siralielemanekle(kok, 1);
		kok = siralielemanekle(kok, 150);
		kok = siralielemanekle(kok, 50);
		yazdir(kok);
		kok = sil(kok, 115);
		kok = sil(kok, 100);
		kok = sil(kok, 150);
		yazdir(kok);
		getchar();
	}
