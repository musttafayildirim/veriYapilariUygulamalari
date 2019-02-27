#include <iostream>

using namespace std;













//iteratif yöntem....
int main() {

	int adet, i, j;
	int kontrol = 0, sayac = 0;

	cout << "Sayi Giriniz (Girilen Sayiya kadar olan asal sayilari bulma): ";
	cin >> adet;

	// 2'den küçük asal sayý olmadýðý için girilen adeti kontrol ediyoruz.
	if (adet < 2)
		cout << "Asal Sayi Bulunamadi!!!";

	else {

		for (i = 2; i <= adet; i++) {

			kontrol = 0;    // Kontrol deðerinin varsayýlan deðeri 0 olarak ata

			for (j = 2; j <= i / 2; j++) {

				if (i % j == 0) {
					kontrol = 1;    // Kendisinden baþka bir sayýya bölünüyorsa kontrol deðiþkenini 1 yap
					break;
				}
			}
			if (kontrol == 0) {        // Kontrol deðiþkeni deðiþmedi ise sayý hiçbir sayýya bölünmemiþtir yani asaldýr
				printf("%d\n", i);
				sayac++;            // Toplam kaç adet asal sayý bulunduðunu sayýyoruz
			}

		}

		cout << "Toplam " << sayac << " tane asal sayi bulunmustur!" << endl;
	}

	system("pause");
	return 0;
}