#include <iostream>
using namespace std;

int main() {
	int n, tmp, cnt = 0;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		tmp = i;
		while (tmp > 9) {
			if (tmp % 10 == 0) cnt++;
			tmp /= 10;
		}
	}
	
	cout << cnt << endl;

	return 0;
}