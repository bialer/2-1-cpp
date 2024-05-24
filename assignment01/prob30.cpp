#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int N, max = 0, keep1, keep2;
	int srt[MAX], end[MAX];
	cin >> N;

	for (int i = 0; i < N; i++) cin >> srt[i] >> end[i];
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (srt[i] < srt[j] && end[i] > end[j]) {
				if (end[j] - srt[j] > max) { 
					max = end[j] - srt[j]; 
					keep1 = i;
					keep2 = j;
				}
			}
			else if (srt[j] < srt[i] && end[j] > end[i]) {
				if (end[i] - srt[i] > max) {
					max = end[i] - srt[i]; 
					keep1 = i;
					keep2 = j;
				}
			}
			else if (srt[i] < srt[j] && end[i] < end[j] && end[i] > srt[j]) {
				if (end[i] - srt[j] > max) {
					max = end[i] - srt[j];
					keep1 = i;
					keep2 = j;
				}
			}
			else if (srt[j] < srt[i] && end[j] < end[i] && end[j] > srt[i]) {
				if (end[j] - srt[i] > max) {
					max = end[j] - srt[i];
					keep1 = i;
					keep2 = j;
				}
			}
		}
	}

	cout << "[" << srt[keep1] << ", " << end[keep1] << "]" << endl;
	cout << "[" << srt[keep2] << ", " << end[keep2] << "]" << endl;

	return 0;
}