#include <cstdlib>	
#include <iostream>

using namespace std;

struct hazirlik{
	int data;
	hazirlik * ileri;
	hazirlik * geri;
};

typedef hazirlik node;

void ekranaBas(node * root){
	while(root != NULL){
		cout << root -> data << endl;
		root = root -> ileri;
	}

	cout << endl;
}

node * ciftYonluSiraliElemanEkle(node * kok, int eklenecekVeri){
	if(kok == NULL){ //burada dikkat edilmesi gereken ilerinin null gösterdiği gibi gerininde null göstermesi gerekiyor...
		kok = (node *)malloc(sizeof(node));
		kok -> ileri = NULL;
		kok -> data = eklenecekVeri;
		kok -> geri = NULL;
		return kok;
	}
	//eklenen değer kökten küçükse root değişir...
	if(kok -> data > eklenecekVeri){
		node * temp = (node *)malloc(sizeof(node));
		temp -> data = eklenecekVeri;
		temp -> ileri = kok;
		kok -> geri = temp;
		return temp;
	}
	
	//eklenen değer roottan büyük ve liste null göstermiyorsa o duruma kadar devam eder..
	node * iter = kok;
	while(iter-> ileri != NULL && iter -> ileri -> data < eklenecekVeri){
		iter = iter -> ileri;	
	}

	node * temp = (node *)malloc(sizeof(node));
	temp -> ileri = iter -> ileri;
	iter -> ileri = temp;
	temp -> geri = iter;
	if(temp -> ileri != NULL)
		temp -> ileri -> geri = temp;
	
	temp -> data = eklenecekVeri;
	return kok;	

}


node * ciftYonluElemanSil(node * kok, int silinecekVeri){
	node * temp;
	node * iter = kok;

	if(kok -> data == silinecekVeri){
		temp = kok;
		cout << "Eski root = " << kok -> data << " Yeni kok = " << kok -> ileri -> data << endl;  
		kok = kok -> ileri;
		free(temp);
		return kok;	
	}

	while(iter -> ileri != NULL && iter -> ileri -> data != silinecekVeri){
		iter = iter -> ileri;		
	}	
	
	if(iter -> ileri == NULL){
		cout << "Aranan sayı bulunamadi" << endl;
		return kok;
	}

	temp = iter -> ileri;
	iter -> ileri = iter -> ileri -> ileri;
	if(temp -> ileri != NULL)
		iter -> ileri -> geri = iter;
	free(temp);
	return kok;		
}



int main(){
node * root;
root = NULL;


root = ciftYonluSiraliElemanEkle(root, 2);
root = ciftYonluSiraliElemanEkle(root, 3);
root = ciftYonluSiraliElemanEkle(root, 3);
root = ciftYonluSiraliElemanEkle(root, 6);
root = ciftYonluSiraliElemanEkle(root, 5);
root = ciftYonluSiraliElemanEkle(root, 8);
root = ciftYonluSiraliElemanEkle(root, 7);
root = ciftYonluSiraliElemanEkle(root, 100);
ekranaBas(root);
cout << "Silme denemeleri" << endl;
//root = ciftYonluElemanSil(root, 500);
root = ciftYonluElemanSil(root, 1);
root = ciftYonluElemanSil(root, 100);
root = ciftYonluElemanSil(root, 3);
root = ciftYonluElemanSil(root, 3);
root = ciftYonluElemanSil(root, 6);
root = ciftYonluElemanSil(root, 2);
ekranaBas(root);






}

