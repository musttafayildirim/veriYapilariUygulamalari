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
void inOrder(struct dugum *r); // Kök ortada
void preOrder(struct dugum *r); // Kök başta
void postOrder(struct dugum *r); // Kök sonda
struct dugum *Silme(struct dugum *,int);
// Arama fonksiyonunu siz main bloğuna ekleyebilirsiniz.
// Burada sadece fonksiyon yazılmıştır.
struct dugum *Arama(struct dugum *);
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
char silme = 'e';
char arama;
int x;

cout << "Inorder Dolasim: ";
inOrder(ana);
cout << endl;
cout << "Preorder Dolasim: ";
preOrder(ana);
cout << endl;
cout << "Postorder Dolasim: ";
postOrder(ana);
cout << endl;

while(1)
{

cout << "Silme islemi yapmak istiyor musunuz?: ";
cin >> silme;
if(silme=='e' || silme == 'E')
{
cout << "Silmek istediğiniz veri:";
cin >> x;
ana = Silme(ana,x);
cout << "Inorder Dolasim: ";
inOrder(ana);
cout << endl;
cout << "Preorder Dolasim: ";
preOrder(ana);
cout << endl;
cout << "Postorder Dolasim: ";
postOrder(ana);
cout << endl;
}

cout << "Arama islemi yapmak istiyor musunuz?: ";
cin >> arama;
if(arama=='e' || arama == 'E')
{
cout << "Aramak istediğiniz veri:";
ana = Arama(ana);
cout << "Inorder Dolasim: ";
inOrder(ana);
cout << endl;
cout << "Preorder Dolasim: ";
preOrder(ana);
cout << endl;
cout << "Postorder Dolasim: ";
postOrder(ana);
cout << endl;
}
}
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
void inOrder(struct dugum *r) // Kök ortada
{
if(r!=NULL){
inOrder(r->sol);
cout << r->value << " ";
inOrder(r->sag);
}
}
void preOrder(struct dugum *r) // Kök başta
{
if(r!=NULL){
cout << r->value << " ";
preOrder(r->sol);
preOrder(r->sag);
}
}
void postOrder(struct dugum *r) // Kök sonda
{
if(r!=NULL){
postOrder(r->sol);
postOrder(r->sag);
cout << r->value << " ";
}
}
/* Silme Fonksiyonu*/
struct dugum *Silme(struct dugum *r,int x)
{
struct dugum *p1,*p2;if(!r)
{
cout << endl << "Eleman Bulunamadi" << endl;
return(r);
}
else
{
if(r->value < x)
{
r->sag = Silme(r->sag,x);
}
else if (r->value >x)
{
r->sol=Silme(r->sol,x);
return r;
}
else
/* no. 2 else */
{
if(r->value == x)
/* no. 2 if */
{
if(r->sol == r->sag)
/*i.e., a leaf node*/
{
free(r);
return(NULL);
}
else if(r->sol==NULL)
/* a sag subdugum */
{
p1=r->sag;
free(r);
return p1;
}
else if(r->sag==NULL)
/* a sol subdugum */
{
p1=r->sol;
free(r);
return p1;
}
else
{
p1=r->sag;
p2=r->sag;
while(p1->sol != NULL)
p1=p1->sol;
p1->sol=r->sol;
free(r);
return p2;
}
}
/*end of no. 2 if */
}
/* end of no. 2 else */
}
return(r);
}
/* Arama ve Yer Değiştirme Fonksiyonu */
struct dugum *Arama(struct dugum *root)
{
int no,i,ino;struct dugum *r;
r=root;
cout << endl << "Aranan Eleman : ";
cin >> no;
fflush(stdin);
while(r) // Arama burada yapılıyor.
{
if(no>r->value)
r=r->sag;
else if(no<r->value)
r=r->sol;
else
break;
}
if(r) // Eleman bulunduysa,
{
cout << endl << "Eleman " << no << " Agacta bulundu = " << r->value;
cout << endl << "Degistirmek icin 1'e Basin ";
cin >> i;
if(i==1)
{
cout << endl << "Yeni Eleman Ekle: ";
cin >> ino;
r->value=ino;
}
else
cout << endl << "Islem Iptal...";
}
else
cout << endl << "Eleman " << no << " Agacta Bulunamadi.... " << endl;
return(root);
}
