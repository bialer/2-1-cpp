#include <iostream>
using namespace std;
const int MAX = 100;

int main() {
	int buy, sell, money = 0, keep = 0;
	int price[MAX];

	for (int i = 0; i < MAX; i++) {
		cin >> price[i];
		if (i > 0 && price[i] > price[i - 1] && keep == 0){
			buy = price[i - 1];
			keep = 1;
		}
		else if (keep == 1 && price[i] < price[i - 1]) {
			sell = price[i - 1];
			money += sell - buy;
			keep = 0;
		}
		if (price[i] == -1) break;
	}

	cout << money << endl;
	
	return 0;
}