#include <iostream>

using namespace std;

int main() {
	//değişken tanımlamalarını yapıyoruz..
	int firstValue, secondValue;
	//burada pointer tanımlaması yapılmıştır.
	int *myPointer;

	//ilk olarak myPointer olarak tanımladığımız pointerımınızı firstValue değişkenimizin adresine atıyoruz..
	myPointer = &firstValue;
	//burada firstValue değişkenimizin adresinin içine 34 değerini atıyoruz..
	*myPointer = 34;
	//sonra myPointer isimli pointerımızı secondValue değişkenimizin adresine atıyoruz
	myPointer = &secondValue;
	//atama yaptığımız adresimizin içerisine 11 değerini atıyoruz..
	*myPointer = 11;

	//burada yaptığımız atama işlemlerini ve onlara karşılık gelen adres değerlerini yazdırıyorumm..
	cout << "First value " << firstValue << " and first value address " << &firstValue << endl;
	cout << "Second value " << secondValue << " and second value address " << &secondValue << endl;

	system("pause");

	return 0;

}