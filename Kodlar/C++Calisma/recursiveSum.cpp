#include<iostream>

using namespace std;

int toplam(int sayi);

int main() {
	
	cout << toplam(5) << endl;
	system("pause");
}

int toplam(int sayi) {
	if (sayi == 1)
		return 1;
	else
		return toplam(sayi - 1) + sayi;
}


