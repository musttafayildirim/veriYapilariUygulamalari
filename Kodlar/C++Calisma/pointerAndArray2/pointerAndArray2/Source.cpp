#include <iostream>

using namespace std;
const int MAX = 3;

int main() {
	int  arr[MAX] = { 10, 100, 200 };
	int *ptrArr[MAX];

	for (int i = 0; i < MAX; i++) {
		ptrArr[i] = &arr[i];
	}

	for (int i = 0; i < MAX; i++) {
		cout << "Value of arr => " << *ptrArr[i] << " and address of array " << ptrArr[i] << endl ;
	}

	system("pause");
	return 0;
}