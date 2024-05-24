#include <iostream>
using namespace std;

int main() {
	int n, k, tmp;
	int arr[100];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	cin >> k;

	for (int i = 0; i < k; i++) {
		tmp = arr[n - 1];
		for (int j = n - 1; j > 0; j--)
			arr[j] = arr[j - 1];
		arr[0] = tmp;
	}

	for (int i = 0; i < n; i++) {
		cout << arr[i] << " ";
	}
	
	return 0;
}