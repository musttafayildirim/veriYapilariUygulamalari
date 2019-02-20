#include <iostream>

using namespace std;

class Human {
public :
	const char *name,*surname;
	int age;
	float weight,height;

};

int main() {
	Human human1;

	//human1 özelliklerini tanýmlýyorum...

	human1.height = 1.87;
	human1.name = "Mustafa";
	human1.surname = "YILDIRIM";
	human1.weight = 90;
	human1.age = 21;

	//deðerleri atamak için bir dizi tanýmlamasý yapýyorum..
	const char *arrName[1][2] = { human1.name, human1.surname };
	float arrOther[1][3] = { human1.height, human1.weight, human1.age };


	//burada da dizilere eklediðimiz deðerleri yazdýrýyoruz..
	for (int i = 0; i < 1; i++) {

		for (int j = 0; j < 2; j++) {
			cout << arrName[i][j] << endl;
		};

		for (int k = 0; k < 3; k++) {
			cout << arrOther[i][k] << endl;
		}
		
	};
	

	system("pause");

	return 0;

}