#include <iostream>
using namespace std;
struct Dugum {
int data;
struct Dugum* sonraki;
};
struct Dugum* top = NULL;
void push(int val)
{
struct Dugum* temp;
 temp = (struct Dugum*)malloc(sizeof(struct Dugum));
 temp->data = val;
 temp->sonraki = top;
 top = temp;
}
void pop()
{
struct Dugum* temp;
if (top == NULL)
 cout << "Yigin bos oldugu icin pop islemi gerceklestirilemez" << endl;
else {
 temp = top;
 cout << "Silinen eleman:" << top->data << endl;
 top = top->sonraki;
 temp->sonraki = NULL;
 free(temp);
 }
} 


void display()
{
struct Dugum* temp;
if (top == NULL) {
 cout << "Yigin bos\n";
 }
else {
 temp = top;
 cout << "Yigin elemanlari : \n";
 while (temp != NULL) {
 cout << temp->data << "\n";
 temp = temp->sonraki;
 }
 }
}
int main()
{
 push(1);
 push(2);
 push(3);
 push(4);
 display();
 pop();
 display();
 return 0;
}
