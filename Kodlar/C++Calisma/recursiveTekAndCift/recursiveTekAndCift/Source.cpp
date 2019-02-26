#include <iostream>

using namespace std;

int tek(int n);
int cift(int n) {
	if (n == 0)
		return 1;
	return tek(n - 1);
}
int tek(int n) {
	if (n == 0)
		return 0;
	if (n == 1)
		return 1;
	return cift(n - 1);
}

int main() {
	cout << tek(6);
	system("pause");
}