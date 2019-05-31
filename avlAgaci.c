#include <stdio.h>
#include <malloc.h>

//Agacimizdaki dugumlerin bilgilerini tutacak olan struct yapisi
//Yukseklik bilgisini de tuttugumuza dikkat edin.
struct node {
	int key;
	struct node *right;
	struct node *left;
	int height;
};

//Asagidaki fonksiyon dugumun yuksekligini return eden yardimci fonksiyondur.
int yukseklik(struct node* dugum)
{
	if (dugum == NULL)
		return 0;
    return dugum->height;
}

//Bu fonksiyon şart fonksiyonlardan biri olmasa da yardimci amacla kullanilmistir
// Gonderilen 2 sayidan hangisi daha buyukse onu return eder. 
int karsilastir(int a, int b)
{
	if (a >= b)
		return a;
	else
		return b;
}

//Dugum olusturup olusan dugumu return eden fonksiyondur.
struct node* dugumOlustur(int key)
{
	struct node* yeniDugum = (struct node*)malloc(sizeof(struct node));
	yeniDugum->key = key;
	yeniDugum->left = NULL;
	yeniDugum->right = NULL;
	
	//Yeni olusturulan dugumlerin (yapraklarin) yukseklikleri 1 olur.
	yeniDugum->height = 1;

	return yeniDugum;
}

//Saga dondurme islemi Sitemiz icerisinde paylastigimiz resimlerdeki durumlardan 
//Degiskenleri daha iyi anlayabilirsiniz
struct node *sagaDondur(struct node *y)
{
    //iliskili dugumleri olusturuyoruz
	struct node *x = y->left;
	struct node *t2 = x->right;
    
    //Saga dondurme islemi burada oluyor
    //Dondurme islemi olduktan sonra dugumler arasindaki iliskileri guncelliyoruz
	x->right = y;
	y->left = t2;

	//Dondurme islemi sonrasinda dugumlerin yuksekliklerini guncelliyoruz.
	y->height = karsilastir(yukseklik(y->left), yukseklik(y->right)) + 1;
	x->height = karsilastir(yukseklik(x->left), yukseklik(x->right)) + 1;

	//Dondurme islemi sonunda olusan yeni root dugumunu return ediyoruz.
	return x;
}

//Saga dondurme isleminde yazdimiz yorum satirlari aynen sola dondurme isleminde de gecerli
// dugumler arasi iliskileri yukaridaki (sitemizdeki) resimlerden kontrol edebilirsiniz.
struct node *solaDondur(struct node *x)
{
	struct node *y = x->right;
	struct node *t2 = y->left;

	y->left = x;
	x->right = t2;

	y->height = karsilastir(yukseklik(y->left), yukseklik(y->right)) + 1;
	x->height = karsilastir(yukseklik(x->left), yukseklik(x->right)) + 1;

	return y;
}

//Denge durumunu kontrol edip return eden fonksiyon
// Sol - Sag yuksekligi esas aldigimiza dikkat edin.
int balanceCheck(struct node* dugum)
{
	if (dugum == NULL)
		return 0;
	else
		return yukseklik(dugum->left) - yukseklik(dugum->right);

}

//AVL Agacina dugum ekleyen ana fonksiyonumuz
struct node* ekle(struct node* kokDugum, int key)
{
    /**** BST INSERTION Baslangici ****/
    // Asagidaki satirlar BST uzerine eleman ekleme isleminden ibarettir.
	if (kokDugum == NULL)
		return dugumOlustur(key);

	if (key < kokDugum->key)
		kokDugum->left = ekle(kokDugum->left, key);
	else if (key > kokDugum->key)
		kokDugum->right = ekle(kokDugum->right, key);
	else
		return kokDugum;
     /**** BST INSERTION Sonu ****/
     
    //Burada yeni eklenen dugumun yuksekligini atiyoruz.
	kokDugum->height = karsilastir(yukseklik(kokDugum->left), yukseklik(kokDugum->right)) + 1;
    
    //Yeni eklenen dugumun denge durumunu elde ediyoruz.
	int balance = balanceCheck(kokDugum);
    
    /*** Sol - Sol && Sag - Sag && Sol - Sag && Sag - Sol Durumlari ***/
    
    /**** Sol Sol Durumu ****/
    // Sol sol durumunda saga dondurme yapilir. if sartlarina dikkat edin)
	if (balance > 1 && key < kokDugum->left->key)
		return sagaDondur(kokDugum);
    
    /**** Sag Sag Durumu ****/
    // sag sag durumunda sola dondurme yapilir. if sartlarina dikkat edin)
	if (balance < -1 && key > kokDugum->right->key )
		return solaDondur(kokDugum);

    /**** Sol Sag Durumu ****/
    // Sol sag durumunda dengesizlik olan dugumun solundaki dugum sola dondurulur
    // Ardindan dugumun kendisi saga dondurulur
	if (balance > 1 && key > kokDugum->left->key)
	{
		kokDugum->left = solaDondur(kokDugum->left);
		return sagaDondur(kokDugum);
	}

    /**** Sag Sol Durumu ****/
    // Sag Sol durumunda dengesizlik olan dugumun sagindaki dugum saga dondurulur
    // Ardindan dugumun kendisi sola dondurulur
	if (balance < -1 && key < kokDugum->right->key)
	{
		kokDugum->right = sagaDondur(kokDugum->right);
		return solaDondur(kokDugum);
	}

	return kokDugum;
}

// Dugum yapimizi preorder sekilde yazdiran fonksiyon. (recursive fonksiyon olduguna dikkat edin)
void preorderYazdir(struct node* root)
{
	if (root != NULL)
	{
		printf(" %d ", root->key);
		preorderYazdir(root->left);
		preorderYazdir(root->right);
	}
}

//Test amacli olarak main fonksiyonunu kullaniyoruz. Baslangicta root = NULL seklinde degisken olusturdugumuza dikkat edin.
int main()
{
	struct node* root = NULL;
	int s;
	root = ekle(root, 10);
	root = ekle(root, 20);
	root = ekle(root, 30);
	root = ekle(root, 40);
	root = ekle(root, 50);
	root = ekle(root, 25);

	preorderYazdir(root);
	scanf("%d", &s);


}
