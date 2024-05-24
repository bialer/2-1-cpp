#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

pair<string, int> strPairCount(string str, vector<pair<string, int>> vp1) {
	int cnt = 0;
	string retStr = "";

	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && 
			(str[i + 1] == ' ' || i == str.length() - 1)) {
			retStr += str[i];
			cnt++;
			if (i != str.length() - 1) retStr += " ";
		}
		else if (str[i] != ' ') retStr += str[i];
	}

	return make_pair(retStr, cnt);
}

vector<pair<string, int>> secondBubbleSort(vector<pair<string, int>> v1) {
	for (int i = v1.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v1[j].second < v1[j + 1].second) {
				pair<string, int> tmp = v1[j];
				v1[j] = v1[j + 1];
				v1[j + 1] = tmp;
			}
		}
	}
	return v1;
}

int main() {
	ifstream infile("sample_lines.txt");
	vector<pair<string, int>> lineWordNum;
	string line;

	while (getline(infile, line)) {
		if (line.empty()) continue;
		string str = strPairCount(line, lineWordNum).first;
		int cnt = strPairCount(line, lineWordNum).second;
		lineWordNum.push_back({ str, cnt });
	}

	lineWordNum = secondBubbleSort(lineWordNum);

	infile.close();

	for (int i = 0; i < lineWordNum.size(); i++) {
		cout << lineWordNum[i].first << ":" << lineWordNum[i].second << endl;
	}
	
	return 0;
}