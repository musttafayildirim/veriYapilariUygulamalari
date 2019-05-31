#include <stdlib.h>
#include <iostream>

using namespace std;

typedef struct n{
    int data;
    struct n * next;
} node;

void bastir(node * r){
    cout << "Tek yönlü bagli liste : ";
    while(r != NULL){
        cout << r->data << " ";
        r = r -> next;
    }
    cout << endl ;
}

node * siraliEkle(node * r, int x){
    if(r == NULL){ //linklist boşsa
        r=(node *)malloc(sizeof(node));
        r->next = NULL;
        r->data = x;
        return r;
    }
    if(r->data >x){ //ilk elemandan kücük olma durumu
                    //root değişiyor
        node * temp = (node *)malloc(sizeof(node));
        temp -> data = x;
        temp -> next = r;
        return temp;
    }
    node * iter = r;
    while(iter -> next != NULL && iter -> next -> data < x){
        iter = iter -> next;
    }
    node * temp = (node *)malloc(sizeof(node));
    temp -> next = iter -> next;
    iter -> next = temp;
    temp -> data = x;
    return r;
}

node * sil(node *r, int x){
    node * temp;
    node * iter = r ;
    if(r->data == x){
        temp = r;
        r = r ->next;
        free(temp);
        return r;
    }
    while (iter -> next != NULL && iter -> next -> data != x){
        iter = iter -> next;
    }
    if(iter -> next == NULL){
        cout << "Sayi bulunamadi";
        return r;
    }
    temp = iter -> next;
    iter -> next = iter -> next -> next;
    free(temp);
    return r;
}

int main(){
    node * root;
    root = NULL;
    root = siraliEkle(root,4);
    root = siraliEkle(root,23);
    root = siraliEkle(root,3);
    root = siraliEkle(root,12);
    root = siraliEkle(root,5);
    bastir(root);
    root = sil(root,3);
    bastir(root);
    }

//Mustafa YILDIRIM 
//36350134690
