// iostream k�t�phanesi ile ekrana yazma ve kullan�c�dan veri alma i�lemlerini yap�yoruz...
#include<iostream>
#include <string>

// rand fonksiyonunu kullanmak i�in tan�mland�..
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Ekrana yaz� yazmak i�in cout kullan�l�r
	cout << "Hello World...\n";
	cout << "Adinizi Giriniz => \n";

	// burada string olarak ad ve soyad diye iki tane de�i�ken tan�ml�yoruz...
	string ad, soyad, durum;
	//string olan bir veriyi bu �ekilde kullan�c�dan al�yoruz..
	getline(cin, ad);
	cout << "Soyadinizi Giriniz => \n";
	getline(cin, soyad);

	cout << "Hos Geldin : " << ad  << " " << soyad << endl;

	
		cout << "\nBug�n nasilsin ";
		getline(cin, durum);
		//if yap�s� ayn� c'da oldu�u gibi...
		if (durum == "iyi") {
			cout << "Daha iyi olursun in�aAllah\n";
		}
		else if (durum == "kotu") {
			cout << "Yak�n zamanda iyi olacaks�n :D\n";
		}
		else {
			cout << "�ok karisik duygular icerisindesin...\n";
		}

	cout << "Simdi senden okul numaran�n son 5 hanesini girmeni istiyorum.";
	
	int okulNumarasiSonBesHane;

	cin >> okulNumarasiSonBesHane;

	cout <<"\nOkul Numaranizin son 5 hanesi " << okulNumarasiSonBesHane << " mi?\nDogru ise(D), yanlis ise(Y) basiniz...";

	char dogruluk;

	cin >> dogruluk;
	//while yap�s� ayn� c'de oldu�u gibi
	while (dogruluk == 'y' || dogruluk == 'Y') {
		cout << "\nOkul Numaranizin son 5 hanesini tekrar giriniz";
		cin >> okulNumarasiSonBesHane;
		cout << "\nOkul Numaranizin son 5 hanesi " << okulNumarasiSonBesHane << " mi?\nDogru ise(D), yanlis ise(Y) basiniz...";
		cin >> dogruluk;
		if (dogruluk == 'D' || dogruluk == 'd')
		{

			break;
		}
		else if (dogruluk == 'y' || dogruluk == 'Y') {
			continue;
		}
	}

	// say� tahmin oyunu yaz�ld�..
	cout << "Tebrikler buraya kadar basariyla geldigin icin :D\n simdi seninle ufak bir oyun oynayacagiz ne dersin? (E) (H)";
	char cevap;
	cin >> cevap;
	if (cevap == 'E' || cevap =='e') {
		srand(time(NULL));
		int randSayi = rand() % 500;
		int tahmin;
		int sayac = 1;
		do {
			cout << "Tahminde bulununuz:D";
			cin >> tahmin;
			if (tahmin>randSayi)
				cout << "Biraz inin" << endl;
			else if (tahmin<randSayi)
				cout << "Biraz cikin" << endl;
			else
				break;
			sayac++;
		} while (randSayi != tahmin);
		cout << "Tebrikler " << sayac << " kerede bildiniz...\n";
		
	}
	else {
		cout << "Pekala oynamayal�m..";
	}

	cout << "Ben gidiyorum hadi kendine iyi bak ..:D\n";

	system("pause");
	return 0;
}