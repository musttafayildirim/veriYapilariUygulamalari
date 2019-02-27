#include <iostream>
using namespace std;

int n;
int faktoriyel(int a) {
	if (a <= 0)
		return 1;
	if (a > 0)
		return a * (faktoriyel(a - 1));
}

int main() {
	cout << "Faktoriyeli alinacak sayi..." << endl;
	cin >> n;
	cout << n << "! =  " << faktoriyel(n) << endl;
	system("pause");
	return 0;
}