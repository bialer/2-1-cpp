#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> sortedSizeStr(vector<string> v1) {
	for (int i = v1.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v1[j].length() > v1[j + 1].length())
				swap(v1[j], v1[j + 1]);
			if (v1[j].length() == v1[j + 1].length()) {
				if (v1[j] > v1[j + 1])
					swap(v1[j], v1[j + 1]);
			}
		}
	}
	return v1;
}

int main() {
	int n;
	string str;
	vector<string> strVec;

	cin >> n;
	cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		strVec.push_back(str);
	}
	
	strVec = sortedSizeStr(strVec);

	for (auto k : strVec)
		cout << k << endl;

	return 0;
}