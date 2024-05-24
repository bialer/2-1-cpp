#include <iostream>
using namespace std;

int main() {
	int N, v;
	cin >> N;

	for (int i = 1; i <= N; i *= 2) {
		v = i;
	}

	while (v > 0) {
		if (N >= v) {
			N -= v;
			cout << 1;
			v /= 2;
		}
		else {
			cout << 0;
			v /= 2;
		}
	}
	
	return 0;
}