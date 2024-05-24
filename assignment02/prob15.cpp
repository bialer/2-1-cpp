#include <iostream>
#include <fstream>
#include <string>
#include <vector>
using namespace std;

vector<string> sepSpace(string line) {
	vector<string> v1;
	int start = 0, area = 0;

	while (line.find(' ', start) != string::npos) {
		area = line.find(' ', start) - start;
		v1.push_back(line.substr(start, area));
		start += area + 1;
	}
	v1.push_back(line.substr(start, line.length() - start));

	return v1;
}

vector<string> sepWord(string line) {
	vector<string> v1;
	int start = 0, area = 0;

	while (line.find('&', start) != string::npos) {
		area = line.find('&', start) - start;
		v1.push_back(line.substr(start, area));
		start += area + 1;
	}
	v1.push_back(line.substr(start, line.length() - start));

	return v1;
}

string delSpace(string str) {
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ' && str[i] != '\t' && !(str.empty()))
			break;
		else if (i == str.length() - 1) return "";
	}
	for (int i = str.length() - 1; i > 0; i--) {
		if (str[i] == ' ' && str[i - 1] == ' ')
			str.erase(str.begin() + i);
	}
	while (str[0] == ' ') str.erase(str.begin());
	while (str[str.length() - 1] == ' ') 
		str.erase(str.length() - 1);

	return str;
}

int checkStrMaxLen(vector<string> v1) {
	int maxLen = 0;
	for (auto k : v1) {
		if (k.length() > maxLen) 
			maxLen = k.length();
	}
	return maxLen;
}

string fillSpace(int n, string str) {
	while (str.length() < n + 3) str += " ";

	return str;
}

int main() {
	ifstream infile("table.txt");
	int row, col;
	string line;
	vector<string> words, lineWord;
	vector<vector<string>> tableVec;

	getline(infile, line);
	vector<string> rowCol = sepSpace(line);
	row = stoi(rowCol[0]);
	col = stoi(rowCol[1]);


	while (getline(infile, line))
		tableVec.push_back(sepWord(line));

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			tableVec[i][j] = delSpace(tableVec[i][j]);
	}

	vector<int> maxLenVec;
	for (int i = 0; i < col; i++) {
		int maxLen;
		vector<string> tmpCol;
		for (int j = 0; j < row; j++)
			tmpCol.push_back(tableVec[j][i]);
		maxLen = checkStrMaxLen(tmpCol);
		maxLenVec.push_back(maxLen);
	}

	int cnt = 0;
	for (int i = 0; i < col; i++) {
		int maxLen = maxLenVec[cnt];
		for (int j = 0; j < row; j++)
			tableVec[j][i] = fillSpace(maxLen, tableVec[j][i]);
		cnt++;
	}

	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++)
			cout << tableVec[i][j];
		cout << endl;
	}
	
	infile.close();

	return 0;
}