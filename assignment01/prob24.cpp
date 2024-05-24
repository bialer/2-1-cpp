#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int n, tmp, max;
	int data[MAX];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> data[i];
	for (int i = n; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (j == 0) max = j;
			else if (data[j] > data[max]) max = j;
		}
		tmp = data[i - 1];
		data[i - 1] = data[max];
		data[max] = tmp;
	}

	for (int i = 0; i < n; i++) cout << data[i] << " ";

	return 0;
}