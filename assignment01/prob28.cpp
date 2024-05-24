#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int N, cnt_max = 0, cnt = 1;
	int arr[MAX];
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N; i++) {
		if (arr[i] <= arr[i + 1]) cnt++;
		if (i == N - 1 || arr[i] > arr[i + 1]) {
			if (cnt_max < cnt) cnt_max = cnt;
			cnt = 1;
		}
	}
	
	cout << cnt_max << endl;

	return 0;
}