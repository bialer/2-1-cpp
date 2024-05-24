#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int n, leader, cnt = 0;
	int arr[MAX], arr_leader[MAX];
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		if (i == 0) arr_leader[0] = arr[i];
		else 
			if (arr[i] >= arr_leader[cnt])
				arr_leader[++cnt] = arr[i];
	}

	cout << ++cnt << ": ";
	for (int i = 0; i < cnt; i++)
		cout << arr_leader[i] << " ";
	
	return 0;
}