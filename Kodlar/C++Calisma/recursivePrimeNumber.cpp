#include <iostream>

using namespace std;

int recursivePrime(int sayi) {
	int adet, i, j;
	int kontrol = 0, sayac = 0;
	if (sayi < 2)
		return 0;
	else {

		for (i = 2; i <= sayi; i++) {

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
}


int main()
{


	recursivePrime(55);

	system("pause");
	return 0;
}

