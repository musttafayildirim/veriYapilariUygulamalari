#include <iostream>

using namespace std;

//Author: Mustafa YILDIRIM....


//burada faktoriyal bulma iþlemi rekürsive olarak yapýlmýþtýr....
/*
int factorial(int number);
int main() {
	cout << factorial(5) << endl;
	system("pause");

}

int factorial(int number) {
	if (number == 0)
		return 1;
	return number * factorial(number - 1);
}

*/



//eðer iteratif bir þekilde yazmak istersek bu þekilde olabilir...
int fact(int sayi);
int main() {
	cout << fact(5) << endl;
	system("pause");
}

int fact(int number) {
	int p = 1;
	for (int i = number; i > 0; i--)
		p *= i;
	return (p);
}


