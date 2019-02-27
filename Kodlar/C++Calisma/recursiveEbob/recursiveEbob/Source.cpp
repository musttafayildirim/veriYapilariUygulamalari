//Author : Nustafa YILDIRIM

#include <iostream>

using namespace std;

int ebob(int x, int y) {
	if (y == 0)
		return x;
	else
		return ebob(y, x%y);
}


int iterEbob(int x, int y);
int main() {
	int m, n, a;
	cout << "Sayilari giriniz...";
	cin >> m >> n;
	a = ebob(m, n);
	cout << m << " "<< n << " = " << a;

	system("pause");
	return 0;
}


/*
ayný fonksiyonun iteratif olarak yazýlmasý..
*/

int iterEbob(int x, int y) {
int s;
while (y != 0) {
	s = x % y;
	x = y;
	y = s;
}
return (x);
}



