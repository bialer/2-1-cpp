#include <iostream>
using namespace std;

int main() {
	int n, k, dif, min, ans;
	int arr[100];
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	ans = arr[0];
	cin >> k;

	for (int i = 0; i < n; i++) {
		dif = arr[i] - k;
		if (dif < 0) dif = -dif;
		if (i == 0) min = dif;
		else {
			if (dif < min) {
				min = dif;
				ans = arr[i];
			}
		}
	}
	cout << ans << endl;
	
	return 0;
}