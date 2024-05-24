#include <iostream>
using namespace std;

int main() {
	int n, cnt0 = 0, cnt1 = 0, cnt2 = 0, cnt3 = 0,
		cnt4 = 0, cnt5 = 0, cnt6 = 0, cnt7 = 0,
		cnt8 = 0, cnt9 = 0;
	cin >> n;

	while (n > 0) {
		if (n % 10 == 0) cnt0++;
		else if (n % 10 == 1) cnt1++;
		else if (n % 10 == 2) cnt2++;
		else if (n % 10 == 3) cnt3++;
		else if (n % 10 == 4) cnt4++;
		else if (n % 10 == 5) cnt5++;
		else if (n % 10 == 6) cnt6++;
		else if (n % 10 == 7) cnt7++;
		else if (n % 10 == 8) cnt8++;
		else cnt9++;
		n /= 10;
	}

	cout << cnt0 << " " << cnt1 << " " << cnt2 << " "
		<< cnt3 << " " << cnt4 << " " << cnt5 << " "
		<< cnt6 << " " << cnt7 << " " << cnt8 << " "
		<< cnt9 << endl;
	
	return 0;
}