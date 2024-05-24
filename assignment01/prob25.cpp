#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int n, tmp, cnt = 0;
	int arr[MAX], ans[MAX];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] != arr[i + 1]) ans[cnt++] = arr[i];
	}
	cout << cnt << ": ";
	for (int i = 0; i < cnt; i++) cout << ans[i] << " ";

	return 0;
}