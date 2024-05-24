#include <iostream>
using namespace std;

int main() {
	int prev, n, next, cnt = 0;

	cin >> prev >> n;

	if (prev <= n) cnt ++;

	while (true) {
		cin >> next;
		if (next == -1) {
			if (prev >= n) cnt++;
			break;
		}
		else if (prev >= n && n <= next) cnt ++;
		prev = n;
		n = next;
	}
	cout << cnt << endl;
	
	return 0;
}