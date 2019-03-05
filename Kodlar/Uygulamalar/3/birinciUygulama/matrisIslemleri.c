#include <iostream>
using namespace std;

void matrisYazdir(int dizi[][4], int);
void matrisYazdir(char dizi[][4], int satirSayisi);


int main()
{
	int iMatris[3][4] = 
	{
	{10, 15, 20, 25},
	{30, 35, 40, 45}, 
	{50, 55, 60, 65}
	};
	
	char cMatris[2][4] = 
	{
	'I',
	'S',
	'T',
	'A',
	'N',
	'B',
	'U',
	'L'	
	};
	
	matrisYazdir(iMatris, 3);
	matrisYazdir(cMatris, 2);
	
	cout << "\n naber";
	return 0;
}

void matrisYazdir(int dizi[][4], int satirSayisi)
{
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<4;j++){
			cout << dizi[i][j] << " ";
		}
		cout << endl;
	}
}


void matrisYazdir(char dizi[][4], int satirSayisi)
{
	int i,j;
	for(i=0;i<satirSayisi;i++){
		for(j=0;j<4;j++){
			cout << dizi[i][j] << " ";
		}
	cout << endl;
	}
}
