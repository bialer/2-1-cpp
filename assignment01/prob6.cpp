#include <iostream>
using namespace std;

int main() {
	int n1, n2, max, min;

	cout << "양의 정수 입력: ";
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		cin >> n2;
		if (i == 0) {
			max = n2;
			min = n2;
		}
		else if (max < n2) max = n2;
		else if (n2 < min) min = n2;

		cout << max - min << endl;
	}
	
	return 0;
}