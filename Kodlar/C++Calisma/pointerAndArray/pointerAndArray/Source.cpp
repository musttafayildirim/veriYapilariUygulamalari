#include <iostream>

	using namespace std;
	const int MAX = 3;
	//burada basit bir dizi uygulamas� yapt�k..
	int main() {
		//ilk olarak diziminiz max eleman say�s� kadar de�eri dizimize atad�k...
		int  arr[MAX] = { 10, 100, 200 };

		//daha sonra bu atad���m�z de�erleri bir for d�ng�s� yard�m�yla yazd�r�yoruz.
		//a�a��daki for d�ng�m�z max de�erimiz neyse oraya kadar d�necek ve o de�ere gelene kadar i de�erimizi art�racak
		// daha sonra o indise kar��l�k gelen arr[i] de�erinin i�ini yazd�racak 
		// bir di�er uygulamam�zda bu i�lemi pointer ile yap�m�n� g�rece�iz..
		for (int i = 0; i < MAX; i++) {

			cout << "Value of arr[" << i << "] = ";
			cout << arr[i] << endl;
		}

		system("pause");
		return 0;
	}
