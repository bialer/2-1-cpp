#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int N, cnt = 0;
	int arr[MAX];
	cin >> N;

	for (int i = 0; i < N; i++) cin >> arr[i];
	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			if (arr[i] > arr[j]) cnt++;
		}
	}

	cout << cnt << endl;
	
	return 0;
}