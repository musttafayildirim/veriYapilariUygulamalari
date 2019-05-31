#include <cstdlib>
#include <iostream>

using namespace std;

struct dairesel{
	int data;
	dairesel * next;

};

typedef dairesel node;

void ekranaYazdir(node * root){
	node * iter = root;
	cout << iter -> data << endl;
	//yazdırılırken dikkat edilmesi gereken iter-> next 'nin root'u görene kadar devam etmesi...
	iter = iter -> next;
	while(iter != root){
		cout << iter -> data << endl;
		iter = iter -> next;	
	}
}


node * daireselListeSiraliElemanEkle(node * root, int eklenecekYeniDeger){
	if(root == NULL){
	root = (node *)malloc(sizeof(node));
	root -> next = root;
	root -> data = eklenecekYeniDeger;
	return root; 
	}	

	if(root -> data > eklenecekYeniDeger){
		node * temp = (node *)malloc(sizeof(node));
		temp -> data = eklenecekYeniDeger;
		temp -> next = root;
		node * iter = root;
		while(iter -> next != root){
			iter = iter -> next;		
		}
		
		iter -> next = temp;
		return temp;
	}
	node * iter = root;
	while(iter -> next != root && iter -> next -> data < eklenecekYeniDeger ){
		iter = iter -> next;
	}
	
	node * temp = (node*)malloc(sizeof(node));
	
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> data = eklenecekYeniDeger;
	return root;
 	
}


node * daireselBagliListeSilme(node * root, int silinecekDeger){
	node * temp;
	node * iter = root;	
	if(root -> data == silinecekDeger){
		while(iter -> next != root){
			iter = iter -> next;
		}
	iter -> next = root -> next;
	free(root);
	return iter -> next;
	}

	while(iter -> next != root && iter -> next -> data < silinecekDeger){
		iter = iter -> next;
	}

	if(iter -> next == root){
		cout << "Aranan Sayi Bulunamadi..." << endl;
		return root;	
	}
	
	temp = iter -> next;
	iter -> next = temp -> next;
	free(temp);
	return root;

	
	
}






int main(){
node * toor;
toor = NULL;

toor = daireselListeSiraliElemanEkle(toor, 450);
toor = daireselListeSiraliElemanEkle(toor, 550);
toor = daireselListeSiraliElemanEkle(toor, 150);
toor = daireselListeSiraliElemanEkle(toor, 50);
toor = daireselListeSiraliElemanEkle(toor, 1);
toor = daireselListeSiraliElemanEkle(toor, 20);
ekranaYazdir(toor);
cout << "silme denemeleri" << endl;
toor = daireselBagliListeSilme(toor, 450);
toor = daireselBagliListeSilme(toor, 150);
toor = daireselBagliListeSilme(toor, 1);
toor = daireselBagliListeSilme(toor, 550);
ekranaYazdir(toor);
}


