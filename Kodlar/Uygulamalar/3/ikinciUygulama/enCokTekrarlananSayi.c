#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
 srand(time(NULL));
	int Array[10];
	int l=1,m;
	for(int i=0;i<10;i++){
    		Array[i] = rand()%51;
 
	}
for(int i=0;i<10;i++){
cout << Array[i] << " ";
}
 int i,k,j;
 int diziElemanSayisi = 10;
 int enFazlaOlan = -1;
 int enFazlaOlanSayi = -1;
 int tekrarlamaSayisi = 0;
 

 for (i = 0; i < diziElemanSayisi; ++i) {
 
  int sayici = 0;

  for (k = 0; k < diziElemanSayisi; ++k)
   if (Array[k] == Array[i])
    ++sayici;

  if (sayici > tekrarlamaSayisi) {
   tekrarlamaSayisi = sayici;
   enFazlaOlanSayi = Array[i];
  }
 }
cout << "\n";
 cout << "En fazla olan sayi : " << enFazlaOlanSayi <<  " \nAdet sayisi: " << tekrarlamaSayisi;
 cout << "\n";
 cout << "\n";
 return 0;

}



