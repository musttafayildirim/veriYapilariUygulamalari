#include <stdlib.h>
#include <iostream>

using namespace std;

struct dugum
{
int value;
dugum *sol;
dugum *sag;
};

struct dugum *ana;
struct dugum *ekle(struct dugum *r, int value);
void postOrder(struct dugum *r); // Kök sonda

int main()
{
ana = NULL;
int n, v;
cout <<  "Kac adet değer eklemek istiyorsunuz?" << endl;
cin >> n;
for(int i=0; i<n; i++){
cout << i+1 <<". Deger ";
cin >> v;
ana = ekle(ana, v);
}

cout << "Postorder Dolasim: ";
postOrder(ana);
cout << endl;

return 0;
}
struct dugum *ekle(struct dugum *r, int value)
{
if(r==NULL)
{
r = (struct dugum*) malloc(sizeof(struct dugum));
r->value = value;
r->sol = NULL;
r->sag = NULL;
}
else if(value < r->value){
r->sol = ekle(r->sol, value);
}
else {
r->sag = ekle(r->sag, value);
}
return r;
}


void postOrder(struct dugum *r) // Kök sonda
{
if(r!=NULL){
postOrder(r->sol);
postOrder(r->sag);
cout << r->value << " ";
}
}
