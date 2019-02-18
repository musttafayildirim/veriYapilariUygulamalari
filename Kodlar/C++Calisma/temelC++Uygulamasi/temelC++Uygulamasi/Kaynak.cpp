// iostream kütüphanesi ile ekrana yazma ve kullanýcýdan veri alma iþlemlerini yapýyoruz...
#include<iostream>
#include <string>

// rand fonksiyonunu kullanmak için tanýmlandý..
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
	// Ekrana yazý yazmak için cout kullanýlýr
	cout << "Hello World...\n";
	cout << "Adinizi Giriniz => \n";

	// burada string olarak ad ve soyad diye iki tane deðiþken tanýmlýyoruz...
	string ad, soyad, durum;
	//string olan bir veriyi bu þekilde kullanýcýdan alýyoruz..
	getline(cin, ad);
	cout << "Soyadinizi Giriniz => \n";
	getline(cin, soyad);

	cout << "Hos Geldin : " << ad  << " " << soyad << endl;

	
		cout << "\nBugün nasilsin ";
		getline(cin, durum);
		//if yapýsý ayný c'da olduðu gibi...
		if (durum == "iyi") {
			cout << "Daha iyi olursun inþaAllah\n";
		}
		else if (durum == "kotu") {
			cout << "Yakýn zamanda iyi olacaksýn :D\n";
		}
		else {
			cout << "Çok karisik duygular icerisindesin...\n";
		}

	cout << "Simdi senden okul numaranýn son 5 hanesini girmeni istiyorum.";
	
	int okulNumarasiSonBesHane;

	cin >> okulNumarasiSonBesHane;

	cout <<"\nOkul Numaranizin son 5 hanesi " << okulNumarasiSonBesHane << " mi?\nDogru ise(D), yanlis ise(Y) basiniz...";

	char dogruluk;

	cin >> dogruluk;
	//while yapýsý ayný c'de olduðu gibi
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

	// sayý tahmin oyunu yazýldý..
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
		cout << "Pekala oynamayalým..";
	}

	cout << "Ben gidiyorum hadi kendine iyi bak ..:D\n";

	system("pause");
	return 0;
}