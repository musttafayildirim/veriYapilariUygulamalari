#include <iostream>

using namespace std;
void  kucult(int x,const char *dizi) {
	if (x == strlen("Mustafa"))
		return;
	cout << dizi++ << endl;
	kucult(x + 1, dizi);
	//cout << dizi-- << endl;
}

int main(int argc,const char* argv[]) {
	kucult(0, "Mustafa");
	system("pause");
	return 0;
}