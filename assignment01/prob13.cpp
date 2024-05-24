#include <iostream>
using namespace std;

int main() {
	int cnt = 0;

	for (int x = 0; x <= 100; x++) {
		for (int y = 0; y <= x * 2 / 3.0; y++) {
			if (x * x + y * y <= 10000) cnt += 1;
		}

		for (int y = 0; y < x * 1 / 3.0; y++) {
			if (x * x + y * y <= 10000) cnt -= 1;
		}
	}

	cout << cnt << endl;

	return 0;
}