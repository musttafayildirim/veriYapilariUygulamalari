//Author : Mustafa YILDIRIM
//Created Date : 20.02.2019
//Bu uygulamada bir �nceki uygulamada oldu�u array kullan�m� yapaca��z ama bu sefer pointer�m�z�n i�erisinde tutttu�umuz
//de�erler string t�rden veriler olacak...

#include <iostream>
const int MAX = 5;

using namespace std;

int main(){
	const char *country[MAX] = {"Britain", "Turkey", "Syria", "Germany", "Russia"};

	for (int i = 0; i < MAX; i++) {
		cout << "Country name: "<<country[i] << " and Country Address: " << (country + i) << endl;
	}

	system("pause");
	return 0;

}