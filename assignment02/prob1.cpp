#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int compareNum(int n1, int n2) {
	vector<int> tmp1, tmp2;

	while (n1 > 0) {
		tmp1.push_back(n1 % 10);
		n1 /= 10;
	}
	while (n2 > 0) {
		tmp2.push_back(n2 % 10);
		n2 /= 10;
	}
	auto it1 = tmp1.end();
	auto it2 = tmp2.end();

	while (it1 != tmp1.begin() && it2 != tmp2.begin()) {
		it1--;
		it2--;
		if (*it1 < *it2) return -1;
		else if (*it1 > *it2) return 1;
	}
	return 0;
}

int main() {
	int n;
	cin >> n;
	vector<int> v1(n);

	for (int i = 0; i < n; i++) cin >> v1[i];

	for (auto i = v1.end() - 1; i > v1.begin(); i--) {
		for (auto j = v1.begin(); j < i; j++) {
			if (compareNum(*j, *(j + 1)) == 1)
				iter_swap(j, j + 1);
			if (compareNum(*j, *(j + 1)) == 0) {
				if (*j > *(j + 1))
					iter_swap(j, j + 1);
			}
		}
	}
	
	for (auto k : v1) cout << k << " ";

	return 0;
}