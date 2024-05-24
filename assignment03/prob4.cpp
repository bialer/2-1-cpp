#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

vector<string> lines;

string delSpace(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == ' ') {
			str.erase(str.begin() + i);
			i--;
		}
	}
	return str;
}

bool check1(int i, int j, int n, char color) {
	if (j >= n) return false;
	else if (lines[i][j + 1] == color) return true;
	else return false;
}

bool check2(int i, int j, int n, char color) {
	if (i >= n || j >= n) return false;
	else if (lines[i + 1][j + 1] == color) return true;
	else return false;
}

bool check3(int i, int j, int n, char color) {
	if (i >= n) return false;
	else if (lines[i + 1][j] == color) return true;
	else return false;
}

bool check4(int i, int j, int n, char color) {
	if (i >= n || j <= 0) return false;
	else if (lines[i + 1][j - 1] == color) return true;
	else return false;
}

bool checkBlack(int i, int j, int n) {
	int cnt = 0;
	while (check1(i, j + cnt, n, '1')) {
		cnt++;
		if (cnt == 4) return true;
	}
	cnt = 0;
	while (check2(i + cnt, j + cnt, n, '1')) {
		cnt++;
		if (cnt == 4) return true;
	}
	cnt = 0;
	while (check3(i + cnt, j, n, '1')) {
		cnt++;
		if (cnt == 4) return true;
	}
	cnt = 0;
	while (check4(i + cnt, j - cnt, n, '1')) {
		cnt++;
		if (cnt == 4) return true;
	}
	return false;
}

bool checkWhite(int i, int j, int n) {
	int cnt = 0;
	while (check1(i, j + cnt, n, '2')) {
		cnt++;
		if (cnt == 4) return true;
	}
	cnt = 0;
	while (check2(i + cnt, j + cnt, n, '2')) {
		cnt++;
		if (cnt == 4) return true;
	}
	cnt = 0;
	while (check3(i + cnt, j, n, '2')) {
		cnt++;
		if (cnt == 4) return true;
	}
	cnt = 0;
	while (check4(i + cnt, j - cnt, n, '2')) {
		cnt++;
		if (cnt == 4) return true;
	}
	return false;
}

int main() {
	ifstream infile("board.txt");
	string line;
	int n, indexN;

	getline(infile, line);
	n = stoi(line);
	indexN = n - 1;

	while (getline(infile, line)){
		line = delSpace(line);
		lines.push_back(line);
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (lines[i][j] == '1') {
				if (checkBlack(i, j, indexN)) {
					cout << "Black";
					return 0;
				}
			}
			else if (lines[i][j] == '2') {
				if (checkWhite(i, j, indexN)) {
					cout << "White";
					return 0;
				}
			}
		}
	}
	cout << "Not Finished" << endl;

	return 0;
}