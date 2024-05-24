#include <iostream>
using namespace std;

int main() {
	int coef, expo_x, expo_y;
	cin >> coef >> expo_x >> expo_y;

	if (coef == 0) cout << 0 << endl;
	else if (expo_x == 0 && expo_y == 0) cout << coef;
	else if (coef == 1);
	else if (coef == -1) cout << "-";
	else cout << coef;
	
	if (expo_x == 0);
	else if (expo_x == 1) cout << "x";
	else cout << "x^" << expo_x;

	if (expo_y == 0) cout << endl;
	else if (expo_y == 1) cout << "y" << endl;
	else cout << "y^" << expo_y << endl;

	return 0;
}