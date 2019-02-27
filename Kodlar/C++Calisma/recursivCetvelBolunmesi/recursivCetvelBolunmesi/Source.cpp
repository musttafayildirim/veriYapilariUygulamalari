#include <iostream>
#include <math.h>

using namespace std;
void yaz(double a1, double a2) {

	double nokta = (a1 + a2) / 2;
	if (abs(a2 - a1) < 2)
		return;
	cout << nokta << endl;
	yaz(a1, nokta);
	yaz(nokta, a2);
}

int main() {
	yaz(0, 20);

	system("pause");
	return 0;
}


