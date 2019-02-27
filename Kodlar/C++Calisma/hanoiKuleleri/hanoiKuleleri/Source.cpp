#include<iostream>

using namespace std;

void hanoi(int n, char x, char y, char z) {
	if (n == 1)
		cout << "Diski " << x << " cubugundan " << z << " cubuguna koy..." << endl;
	else {
		hanoi(n - 1, x, z, y);
		hanoi(1, x, y, z);
		hanoi(n - 1, y, x, z);
	}
}

int main() {
	int n;
	cout << "Disk sayisi N: ";
	cin >> n;
	hanoi(n, 'A', 'B', 'C');

	system("pause");
	return 0;
}


