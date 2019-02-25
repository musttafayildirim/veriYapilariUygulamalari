//fibonacci hesab�n�n �zyinelemesiz ger�ekle�tirilmi� hali :D

#include <iostream>
#include <ctime>
using namespace std;
/*
long noRecursiveFibonacci(unsigned int sayi) {
	long fibonacci1 = 0, fibonacci2 = 1, fibonacci;

	if (sayi <= 1) {
		return sayi;
	}
	for (int i = 0; i <= sayi; i++) {
		fibonacci = fibonacci1 + fibonacci2;
		fibonacci2 = fibonacci1;
		fibonacci1 = fibonacci;
	}
	return fibonacci;
}

int main() {
	cout << noRecursiveFibonacci(50) <<endl;
	system("pause");
	return 0;
}

*/
//�imdi bu i�lemi rek�rsive olarak yapaca��z bakal�m nas�l bir performans� olacak...

long fibo(unsigned int n) {
	return n <= 1 ? n : fibo(n - 1) + fibo(n + 2);
}

int main() {
	time_t begin, end;
	long res;
	int n;

	for (n = 0; n < 5; n++) {
		time(&begin);
		res = fibo(n);
		time(&end);

		cout << "%3i\t%9lit%-20.3f\n" << n << res << difftime(end, begin);

	}
	system("pause");
	return 0;
}