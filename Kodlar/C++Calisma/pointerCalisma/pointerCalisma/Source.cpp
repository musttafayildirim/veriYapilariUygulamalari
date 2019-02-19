#include <iostream>

using namespace std;

int main() {
	//deðiþken tanýmlamalarýný yapýyoruz..
	int firstValue, secondValue;
	//burada pointer tanýmlamasý yapýlmýþtýr.
	int *myPointer;

	//ilk olarak myPointer olarak tanýmladýðýmýz pointerýmýnýzý firstValue deðiþkenimizin adresine atýyoruz..
	myPointer = &firstValue;
	//burada firstValue deðiþkenimizin adresinin içine 34 deðerini atýyoruz..
	*myPointer = 34;
	//sonra myPointer isimli pointerýmýzý secondValue deðiþkenimizin adresine atýyoruz
	myPointer = &secondValue;
	//atama yaptýðýmýz adresimizin içerisine 11 deðerini atýyoruz..
	*myPointer = 11;

	//burada yaptýðýmýz atama iþlemlerini ve onlara karþýlýk gelen adres deðerlerini yazdýrýyorumm..
	cout << "First value " << firstValue << " and first value address " << &firstValue << endl;
	cout << "Second value " << secondValue << " and second value address " << &secondValue << endl;

	system("pause");

	return 0;

}