#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

vector<string> dic, words;
vector<vector<string>> puzzle;

vector<string> checkDuple(vector<string> v1) {
	for (int i = 0; i < words.size(); i++) {
		for (int j = 0; j < v1.size(); j++) {
			if (words[i] == v1[j]) {
				v1.erase(v1.begin() + j);
				j--;
			}
		}
	}
	return v1;
}

void setWords(vector<string> v1) {
	for (int i = 0; i < v1.size(); i++)
		words.push_back(v1[i]);
}

void compareStr(string str, vector<string>& v1) {
	for (auto d : dic) {
		if (str == d)
			v1.push_back(d);
	}
}

void check1(int row, int col, int N, string str) {
	vector<string> strings;

	row--;
	col--;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		row--;
		col--;
	}
	if(!(strings.empty())){
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check2(int row, int col, int N, string str) {
	vector<string> strings;

	col--;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		col--;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check3(int row, int col, int N, string str) {
	vector<string> strings;

	row++;
	col--;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		row++;
		col--;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check4(int row, int col, int N, string str) {
	vector<string> strings;

	row++;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		row++;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check5(int row, int col, int N, string str) {
	vector<string> strings;

	row++;
	col++;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		row++;
		col++;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check6(int row, int col, int N, string str) {
	vector<string> strings;

	col++;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		col++;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check7(int row, int col, int N, string str) {
	vector<string> strings;

	row--;
	col++;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		row--;
		col++;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void check8(int row, int col, int N, string str) {
	vector<string> strings;

	row--;
	while (row >= 0 && row < N && col >= 0 && col < N) {
		str += puzzle[row][col];
		compareStr(str, strings);
		row--;
	}
	if (!(strings.empty())) {
		strings = checkDuple(strings);
		setWords(strings);
	}
}

void checkWord(int row, int col, int N) {
	string str = puzzle[row][col];

	for (auto d : dic) {
		if (str == d){
			if (find(words.begin(), words.end(), str)
				== words.end()) words.push_back(str);
		}
	}
	check1(row, col, N, str);
	check2(row, col, N, str);
	check3(row, col, N, str);
	check4(row, col, N, str);
	check5(row, col, N, str);
	check6(row, col, N, str);
	check7(row, col, N, str);
	check8(row, col, N, str);
}

int main() {
	ifstream dicTxt("dictionary.txt");
	ifstream puzzleTxt("puzzle.txt");
	string line, str;

	while (getline(dicTxt, line))
		dic.push_back(line);

	getline(puzzleTxt, line);
	int N = stoi(line);

	for (int i = 0; i < N; i++) {
		getline(puzzleTxt, line);
		stringstream ch(line);
		vector<string> puzzleLine;

		while (getline(ch, str, ' '))
			puzzleLine.push_back(str);
		puzzle.push_back(puzzleLine);
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			checkWord(i, j, N);
	}

	for (auto a : words) 
		cout << a << endl;
	
	return 0;
}