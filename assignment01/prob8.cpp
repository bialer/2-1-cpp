#include <iostream>
using namespace std;

int main() {
	int a, b, c, d;
	cin >> a >> b >> c >> d;

	if (d >= a && b >= c) cout << "yes" << endl;
	else cout << "no" << endl;
	
	return 0;
}