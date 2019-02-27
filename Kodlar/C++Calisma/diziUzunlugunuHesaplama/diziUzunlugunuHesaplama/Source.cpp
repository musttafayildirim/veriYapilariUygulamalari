#include <iostream>

using namespace std;

int diziHesapla(char *s) {
	return s[0] == NULL ? 0 : (1 + diziHesapla(s + 1));
}

int main() {
	char str[100];
	cin >> str;
	cout << str << " " << diziHesapla(str) << endl;

	system("pause");
	return 0;
}