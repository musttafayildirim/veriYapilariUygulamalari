#include <iostream>
#include <cmath>
#define PI 3.14
using namespace std;
int main()
{
	float ucgenKenar, ucgenYukseklik;
	float kareKenar;
	float cemberYaricap;
	float ucgenAlan, kareAlan, cemberAlan;
	/* Kullanýcýdan deðerler alýnýyor */
	cout << "Ucgenin Taban Kenarini Giriniz: ";
	cin >> ucgenKenar;
	cout << "Ucgenin Yuksekligini Giriniz: ";
	cin >> ucgenYukseklik;
	cout << "Karenin Kenarini Giriniz: ";
	cin >> kareKenar;
	cout << "Cemberin Yaricapini Giriniz: ";
	cin >> cemberYaricap;
	ucgenAlan = (ucgenKenar * ucgenYukseklik) / 2;
	kareAlan = pow(kareKenar, 2);
	cemberAlan = pow(cemberYaricap, 2) * PI;
	cout << "Ucgenin Alani: " << ucgenAlan << endl;
	cout << "Karenin Alani: " << kareAlan << endl;
	cout << "Cemberin Alani: " << cemberAlan << endl;
	system("pause");
	return 0;
}