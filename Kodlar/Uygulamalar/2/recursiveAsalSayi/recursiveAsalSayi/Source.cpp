#include <iostream>

using namespace std;













//iteratif y�ntem....
int main() {

	int adet, i, j;
	int kontrol = 0, sayac = 0;

	cout << "Sayi Giriniz (Girilen Sayiya kadar olan asal sayilari bulma): ";
	cin >> adet;

	// 2'den k���k asal say� olmad��� i�in girilen adeti kontrol ediyoruz.
	if (adet < 2)
		cout << "Asal Sayi Bulunamadi!!!";

	else {

		for (i = 2; i <= adet; i++) {

			kontrol = 0;    // Kontrol de�erinin varsay�lan de�eri 0 olarak ata

			for (j = 2; j <= i / 2; j++) {

				if (i % j == 0) {
					kontrol = 1;    // Kendisinden ba�ka bir say�ya b�l�n�yorsa kontrol de�i�kenini 1 yap
					break;
				}
			}
			if (kontrol == 0) {        // Kontrol de�i�keni de�i�medi ise say� hi�bir say�ya b�l�nmemi�tir yani asald�r
				printf("%d\n", i);
				sayac++;            // Toplam ka� adet asal say� bulundu�unu say�yoruz
			}

		}

		cout << "Toplam " << sayac << " tane asal sayi bulunmustur!" << endl;
	}

	system("pause");
	return 0;
}