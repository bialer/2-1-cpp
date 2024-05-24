#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int n, tmp;
	int srt[MAX], end[MAX];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> srt[i] >> end[i];
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (srt[j] > srt[j + 1]) {
				tmp = srt[j];
				srt[j] = srt[j + 1];
				srt[j + 1] = tmp;
				tmp = end[j];
				end[j] = end[j + 1];
				end[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n - 1; i++) {
		if (srt[i] == srt[i + 1]) {
			if (end[i] > end[i + 1]) {
				tmp = end[i + 1];
				end[i + 1] = end[i];
				end[i] = tmp;
			}
		}
	}

	for (int i = 0; i < n; i++)
		cout << srt[i] << " " << end[i] << endl;

	return 0;
}