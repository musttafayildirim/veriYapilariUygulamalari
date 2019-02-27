#include <iostream>

using namespace std;

//Author : Mustafa YILDIRIM...

//hammin sayý olup olmadýðýnýn kotrolü yapýlýyor...
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

//verilen sayýlar teker teker kontrol ediliyor ve hamminglerse ekrana yazýlmalarý saðlanýyor...
int hamming(int x) {
	if (x == 1)
		return 1;
	hamming(x - 1);
	if (isHamming(x))
		cout << x <<" ";
}

//hamming( buraya yazýlan sayýya kadar tekrar ediyor...)
int main() {
	hamming(1000);

	system("pause");
	return 0;
}