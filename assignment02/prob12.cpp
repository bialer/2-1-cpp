#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> delDuple(vector<int> v1) {
	for (int i = 0; i < v1.size() - 1; i++) {
		if (v1[i] == v1[i + 1]) {
			v1.erase(v1.begin() + i);
			i--;
		}
	}
	return v1;
}

int main() {
	int n1, n2;
	vector<int> nums;

	cin >> n1;
	for (int i = 0; i < n1; i++) {
		cin >> n2;
		nums.push_back(n2);
	}
	sort(nums.begin(), nums.end());

	nums = delDuple(nums);

	cout << nums.size() << ": ";
	for (auto k : nums) cout << k << " ";
	
	return 0;
}