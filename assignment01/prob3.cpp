#include <iostream>]
using namespace std;

int main() {
	int n1;
	double n2 = 1, sum = 0;

	cout << "양의 정수 입력: ";
	cin >> n1;

	for (int i = 1; i <= n1; i++) {
		n2 /= i;
		sum += n2;
	}

	cout << sum << endl;
	
	return 0;
}