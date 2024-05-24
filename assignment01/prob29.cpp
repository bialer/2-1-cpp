#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int N, K, sum = 0, cnt = 0, cnt_max = 0;
	int arr[MAX];
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	cin >> K;

	for (int j = 0; j < N; j++)
		for (int i = j; i < N; i++) {
			if (sum + arr[i] <= K) {
				sum += arr[i];
				cnt++;
			}
			else {
				if (cnt_max < cnt) cnt_max = cnt;
				cnt = 0;
				sum = 0;
				break;
			}
			if (i == N - 1) {
				if (cnt_max < cnt) cnt_max = cnt;
				cnt = 0;
				sum = 0;
			}
		}

	cout << cnt_max << endl;
	
	return 0;
}