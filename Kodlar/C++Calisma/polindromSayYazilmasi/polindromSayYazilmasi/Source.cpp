#include <iostream>
using namespace std;

void polYaz(int n) {
	if (n == 1)
		cout << "1";
	else {
		polYaz(n - 1);
		cout << n ;
		polYaz(n - 1);
	}
}

int main() {
	int n;
	cout << "Sayi : ";
	cin >> n;
	polYaz(n);
	cout << endl;
	system("pause");
	return 0;

}