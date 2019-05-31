#include <iostream>
#include <cstdlib>

using namespace std;

struct liste{
	int deger;
	liste * sonraki;
};

typedef liste list;


//listedeki ifadeleri ekrana bastıran fonksiyon

void ekranaYaz(list * listeyiGoster){
	while(listeyiGoster != NULL){
		cout << listeyiGoster -> deger << endl;
		listeyiGoster = listeyiGoster -> sonraki;
	}
}


// listeye sıralı değer ekleme

list * siraliEkle(list * dugum, int eklenen){
	// eğer düğüm komple boşsa	
	if(dugum == NULL){
		dugum = (list *)malloc(sizeof(list));
		dugum -> deger = eklenen;
		dugum -> sonraki = NULL;
		return dugum;	
	}
	//eklenen değer roottan küçükse burada rootun değişmesi
	// gerekiyor....
	if(dugum -> deger > eklenen){
		list * degisen = (list *)malloc(sizeof(list));
		degisen -> deger = eklenen;
		degisen -> sonraki = dugum;
		dugum = degisen;
		return degisen;		
	}
	
	//diğer durumlar .....
	list * gidici = dugum;
	while(gidici -> sonraki != NULL && gidici -> sonraki -> deger < eklenen){
		gidici = gidici -> sonraki;
	}
	
	list * degisen = (list *)malloc(sizeof(list));
	degisen -> sonraki = gidici -> sonraki;
	gidici -> sonraki = degisen;
	degisen -> deger = eklenen;
	return dugum;
}
	

//bağlı listede silme işlemi

list * sil(list * dugum, int aranan){
	list * temp;
	list * iter = dugum;
	// sileceğimiz ifade başta olursa önce bir temp değişkeni
	// ile kökümüzü tutuyoruz. sonra dugum değişkenimizi 
	// sonrakine atıyoruz ve temp'i hafızadan temizliyoruz...

	if(dugum -> deger == aranan){
		temp = dugum;
		dugum = dugum -> sonraki;
		cout << "Root degeri olan " << temp -> deger << " silindi" << endl;
		free(temp);
		return dugum;
	}
	
	//ama silinecek ifade root harici bir yerde olursa
	while(iter -> sonraki != NULL && iter -> sonraki -> deger != aranan){
		iter = iter -> sonraki;	
	}
	
	//aranan sayı yoksa	
	if(iter -> sonraki == NULL){
		cout << "Aranan Sayi bulunamadi...";
		return dugum;
	}

	//sayıyı bulursak
	temp = iter -> sonraki;
	iter -> sonraki = iter -> sonraki -> sonraki;
	free(temp);
	return dugum;
}



int main(){
list * root;
root = NULL;

root = siraliEkle(root,19);
root = siraliEkle(root,5);
root = siraliEkle(root,5);
root = siraliEkle(root,15);
root = siraliEkle(root,95);
ekranaYaz(root);
root = sil(root,5);
ekranaYaz(root);

return 0;
}
