#include <iostream>
using namespace std;

int dev(int a, int b) {
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main() {
	int cnt = 0;

	for (int i = 2; i <= 100; i++) {
		for (int j = i + 1; j <= 100; j++) {
			for (int k = j + 1; k <= 100; k++) {
				if (dev(i, j) == 1 && dev(i, k) == 1 && dev(j, k) == 1) cnt++;
			}
		}
	}
	cout << cnt << endl;
	
	return 0;
}