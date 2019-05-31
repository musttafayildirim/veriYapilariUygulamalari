#include <stdlib.h>
#include <iostream>

using namespace std;

struct bagliListe{
	int data;
	bagliListe * next;
};
typedef bagliListe node;


node * siraliEkle(node * root, int eklenen){
	if(root == NULL){
		root = (node *)malloc(sizeof(node));
		root -> data = eklenen;
		root -> next = NULL;
		return root;		
	}
	
	if (root -> data > eklenen){
		node * temp = (node *)malloc(sizeof(node));
		temp -> data = eklenen;
		temp -> next = root;
		return temp;
		}
		
	node * iter = root;
	while(iter -> next != NULL && iter -> next -> data < eklenen){
				iter = iter -> next;
	}
	node * temp = (node *)malloc(sizeof(node));
	temp -> next = iter -> next;
	iter -> next = temp;
	temp -> data = eklenen;
	return root;
	
				
}

void ekranaBas(node * yaz){
	while(yaz != NULL){
			cout << yaz -> data << endl ;
			yaz = yaz -> next;
	}
}


int main(){
node * root;
root = NULL;
root = siraliEkle(root, 50);
root = siraliEkle(root, 100050);
root = siraliEkle(root, 150);
root = siraliEkle(root, 300);
root = siraliEkle(root, 1);
root = siraliEkle(root, 550);
ekranaBas(root);

return 0;
}


