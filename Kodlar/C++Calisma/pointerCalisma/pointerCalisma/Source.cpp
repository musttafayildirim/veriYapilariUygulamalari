#include <iostream>

using namespace std;

int main() {
	//de�i�ken tan�mlamalar�n� yap�yoruz..
	int firstValue, secondValue;
	//burada pointer tan�mlamas� yap�lm��t�r.
	int *myPointer;

	//ilk olarak myPointer olarak tan�mlad���m�z pointer�m�n�z� firstValue de�i�kenimizin adresine at�yoruz..
	myPointer = &firstValue;
	//burada firstValue de�i�kenimizin adresinin i�ine 34 de�erini at�yoruz..
	*myPointer = 34;
	//sonra myPointer isimli pointer�m�z� secondValue de�i�kenimizin adresine at�yoruz
	myPointer = &secondValue;
	//atama yapt���m�z adresimizin i�erisine 11 de�erini at�yoruz..
	*myPointer = 11;

	//burada yapt���m�z atama i�lemlerini ve onlara kar��l�k gelen adres de�erlerini yazd�r�yorumm..
	cout << "First value " << firstValue << " and first value address " << &firstValue << endl;
	cout << "Second value " << secondValue << " and second value address " << &secondValue << endl;

	system("pause");

	return 0;

}