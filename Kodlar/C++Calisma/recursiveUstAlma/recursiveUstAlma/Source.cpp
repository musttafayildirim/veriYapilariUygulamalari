#include <iostream>

using namespace std;

float ust(float a, int n) {
	if (a == 0)
		return 0;
	if (a > 0 && n == 0)
		return 1;
	if (a > 0 && n == 1)
		return a;
	if (a > 0 && n > 1)
		return a * (ust(a, n - 1));
}

int main() {
	cout << ust(5, 2) << endl;
	system("pause");
}



