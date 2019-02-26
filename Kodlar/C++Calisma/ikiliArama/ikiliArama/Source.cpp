#include <iostream>
using namespace std;

int ikiliArama(int dizi[], int elemanSayisi, int arananSayi)
{
	int dizininOrtasi, Sol = 0, Sag = elemanSayisi - 1;
	while (Sol <= Sag)
	{
		dizininOrtasi = (Sol + Sag) / 2;
		if (arananSayi == dizi[dizininOrtasi])
			return dizininOrtasi;
		else if (arananSayi>dizi[dizininOrtasi])
			Sol = dizininOrtasi + 1;
		else
			Sag = dizininOrtasi - 1;
	}
	return -1;
}


int main()
{
	int indis, arananSayi, dizi[] = {10,20,30,54,55,57,59,66,77,89 };
	cout << "Aranan sayiyi girin: ";
	cin >> arananSayi;
	indis = ikiliArama(dizi, 10, arananSayi);
	if (indis == -1)
		cout << "Aranan sayi bulunamadi!";
	else
		cout << "Aranan sayi " << indis << " indisli elemandir.\n" << endl;
	system("pause");
	return 0;
}