#include <iostream>

using namespace std;

//Author : Mustafa YILDIRIM...

//hammin say� olup olmad���n�n kotrol� yap�l�yor...
int isHamming(int x)
{
	if (x == 1)
		return 1;
	if (x % 2 == 0)
		return isHamming(x / 2);
	if (x % 3 == 0)
		return isHamming(x / 3);
	if (x % 5 == 0)
		return isHamming(x / 5);
	return 0;
}

//verilen say�lar teker teker kontrol ediliyor ve hamminglerse ekrana yaz�lmalar� sa�lan�yor...
int hamming(int x) {
	if (x == 1)
		return 1;
	hamming(x - 1);
	if (isHamming(x))
		cout << x <<" ";
}

//hamming( buraya yaz�lan say�ya kadar tekrar ediyor...)
int main() {
	hamming(1000);

	system("pause");
	return 0;
}