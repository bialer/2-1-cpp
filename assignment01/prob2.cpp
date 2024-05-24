#include <iostream>
using namespace std;

int main() {
	int n1;
	double n2 = 1, sum = 1;

	cout << "양의 정수 입력: ";
	cin >> n1;

	for (double i = 0; i < n1; i++) {
		n2 *= -0.5;
		sum += n2;
	}
	
	cout << sum << endl;

	return 0;
}