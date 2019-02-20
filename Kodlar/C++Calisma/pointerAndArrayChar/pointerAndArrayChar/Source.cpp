//Author : Mustafa YILDIRIM
//Created Date : 20.02.2019
//Bu uygulamada bir önceki uygulamada olduðu array kullanýmý yapacaðýz ama bu sefer pointerýmýzýn içerisinde tutttuðumuz
//deðerler string türden veriler olacak...

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