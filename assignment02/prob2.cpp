#include <iostream>
#include <string>
#include <vector>
using namespace std;

vector<string> strToVec(string str, vector<string> v1) {
	string strTmp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' &&
			(str[i + 1] == ' ' || i == str.length() - 1)) {
			strTmp += str[i];
			v1.push_back(strTmp);
			strTmp = "";
		}
		else if (str[i] != ' ') strTmp += str[i];
	}
	return v1;
}

void strOut(vector<string> v1) {
	int cnt = 0;
	for (int i = 0; i < v1.size(); i++) {
		if (i != v1.size() - 1) {
			cout << v1[i] << " ";
			cnt += v1[i].size() + 1;
		}
		else {
			cout << v1[i] << ":";
			cnt += v1[i].size();
			cout << cnt << endl;
		}
	}
}

 int main() {
	string str;
	while (true) {
		vector<string> v1;
		getline(cin, str);
		if (str == "exit") break;
		v1 = strToVec(str, v1);
		strOut(v1);
	}
	
	return 0;
}