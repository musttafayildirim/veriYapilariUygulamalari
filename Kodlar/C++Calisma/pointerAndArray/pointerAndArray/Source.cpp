#include <iostream>

	using namespace std;
	const int MAX = 3;
	//burada basit bir dizi uygulamasý yaptýk..
	int main() {
		//ilk olarak diziminiz max eleman sayýsý kadar deðeri dizimize atadýk...
		int  arr[MAX] = { 10, 100, 200 };

		//daha sonra bu atadýðýmýz deðerleri bir for döngüsü yardýmýyla yazdýrýyoruz.
		//aþaðýdaki for döngümüz max deðerimiz neyse oraya kadar dönecek ve o deðere gelene kadar i deðerimizi artýracak
		// daha sonra o indise karþýlýk gelen arr[i] deðerinin içini yazdýracak 
		// bir diðer uygulamamýzda bu iþlemi pointer ile yapýmýný göreceðiz..
		for (int i = 0; i < MAX; i++) {

			cout << "Value of arr[" << i << "] = ";
			cout << arr[i] << endl;
		}

		system("pause");
		return 0;
	}
