#include <iostream>
using namespace std;

int main() {
	int f1 = 1, f2 = 1, tmp, n;

	cout << "2 이상 30 이하 정수 입력: ";
	cin >> n;

	for (int i = 1; i < n; i++) {
		tmp = f2;
		f2 += f1;
		f1 = tmp;
	}
	
	cout << f2 << endl;

	return 0;
}