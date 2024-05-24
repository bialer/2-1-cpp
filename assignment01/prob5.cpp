#include <iostream>
using namespace std;

int main() {
	int n1, n2, min = -1;

	cout << "양의 정수 입력: ";
	cin >> n1;

	for (int i = 0; i < n1; i++) {
		cin >> n2;
		if (min == -1 && -1 < n2) min = n2;
		else if (n2 < min && -1 < n2) min = n2;
	}
	cout << min << endl;
	
	return 0;
}