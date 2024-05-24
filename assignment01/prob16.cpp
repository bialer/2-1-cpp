#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
	int cnt1 = 0, cnt2 = 0, tmp_cnt2 = 0;
	srand((unsigned int)time(NULL));
	
	for (int i = 0; i < 1000000; i++) {
		for (int j = 0; j < 6; j++){
			if (rand() % 6 + 1 == 1) {
				cnt1++;
				break;
			}
		}
		for (int k = 0; k < 12; k++) {
			if (rand() % 6 + 1 == 1) tmp_cnt2++;
			if (tmp_cnt2 == 2) {
				cnt2++;
				break;
			}
		}
		tmp_cnt2 = 0;
	}

	cout << cnt1 << " " << cnt2 << endl;

	return 0;
}