#include <iostream>
#include <string>
#include <vector>
using namespace std;

void sorted_merge(vector<string>& first, vector<string>& second) {
	for (int i = 0; i < second.size(); i++) {
		for (int j = 0; j < first.size(); j++) {
			if (j == 0 && second[i] <= first[j]){
				first.insert(first.begin(), second[i]);
				break;
			}
			else if (j != 0 && first[j - 1] < second[i] && second[i] <= first[j]){
				first.insert(first.begin() + j, second[i]);
				break;
			}
			else if (j == first.size() - 1 && first[j] < second[i]) {
				first.push_back(second[i]);
				break;
			}
		}
	}
}

int main() {
	int m, n;
	string str;
	vector<string> first, second;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> str;
		first.push_back(str);
	}
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> str;
		second.push_back(str);
	}

	sorted_merge(first, second);

	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}