#include <iostream>
using namespace std;

int main() {
	int n, rem;
	cin >> n;

	while (n > 0) {
		rem = n % 10;
		cout << rem;
		n /= 10;
	}
	
	return 0;
}