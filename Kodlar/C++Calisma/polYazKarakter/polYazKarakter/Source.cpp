#include <iostream>
//girilen sayýya kadar polindrom harf üreten fonksiyon...

void polYaz(int n) {
	char ch = 96;
	if (n == 1)
		std::cout << "a";
	else {
		polYaz(n - 1);
		std::cout << char(ch + n);
		polYaz(n - 1);
	}
}

int main() {
	int n;
	std::cout << "Sayi : ";
	std::cin >> n;
	polYaz(n);
	std::cout << std::endl;

	system("pause");
	return 0;

}