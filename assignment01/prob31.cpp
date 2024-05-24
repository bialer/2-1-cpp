#include <iostream>
using namespace std;

int main() {
	int n = 7, tmp, cnt = 1;
	int arr[7];

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = n - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (arr[j] > arr[j + 1]) {
				tmp = arr[j + 1];
				arr[j + 1] = arr[j];
				arr[j] = tmp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (arr[i + 1] == arr[i] + 1) cnt++;
		else if (arr[i + 1] == arr[i]);
		else if (cnt < 5) cnt = 1;
		
		if (cnt == 5) {
			cout << "YES" << endl;
			return 0;
		}
	}
	cout << "NO" << endl;
	
	return 0;
}