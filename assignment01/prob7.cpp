#include <iostream>
using namespace std;

int main() {
	int y1, y2, m1, m2, d1, d2;

	cout << "날짜 두 개 입력: ";
	cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;

	if (y1 < y2) cout << -1 << endl;
	else if (y1 > y2) cout << 1 << endl;
	else {
		if (m1 < m2) cout << -1 << endl;
		else if (m1 > m2) cout << 1 << endl;
		else {
			if (d1 < d2) cout << -1 << endl;
			else if (d1 > d2) cout << 1 << endl;
			else cout << 0 << endl;
		}
	}
	
	return 0;
}