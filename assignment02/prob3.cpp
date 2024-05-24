#include <iostream>
#include <fstream>
#include <string>
#include <cctype>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> setWord(string str) {
	int start = 0, end = 0;
	string word;
	vector<string> words;

	while (true) {
		end = str.find(" ", start);
		if (end != string::npos) {
			int area = end - start;
			word = str.substr(start, area);
			words.push_back(word);
			start = end + 1;
		}
		else {
			word = str.substr(start);
			words.push_back(word);
			break;
		}
	}
	return words;
}

vector<pair<string, int>> firstSort(vector<pair<string, int>> v1) {
	for (int i = v1.size() - 1; i > 0; i--) {
		for (int j = 0; j < i; j++) {
			if (v1[j].second == v1[j+1].second){
				if (v1[j].first > v1[j + 1].first) {
					pair<string, int> tmp = v1[j];
					v1[j] = v1[j + 1];
					v1[j + 1] = tmp;
				}
			}
		}
	}
	return v1;
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
	ifstream infile("input3.txt");
	vector<string> lines, words;
	vector<pair<string, int>> numNCnt;
	string line;

	while (getline(infile, line))
		lines.push_back(line);

	for (int i = 0; i < lines.size(); i++) {
		for (int j = 0; j < lines[i].size(); j++) {
			if (isalpha(lines[i][j])) lines[i][j] = tolower(lines[i][j]);
		}
	}

	for (auto i : lines) {
		if (!i.empty()){
			vector<string> lineWords = setWord(i);
			words.insert(words.end(), lineWords.begin(), lineWords.end());
		}
	}

	numNCnt.push_back({ words[0], 1 });
	int cnt = 0;

	for (auto k : words) {
		if (cnt == 0) {
			cnt++;
			continue;
		}
		for (int i = 0; i < numNCnt.size(); i++) {
			if (k == numNCnt[i].first) {
				numNCnt[i].second++;
				break;
			}
			else if (i == numNCnt.size() - 1) {
				numNCnt.push_back({ k, 1 });
				break;
			}
		}
	}

	numNCnt = secondBubbleSort(numNCnt);
	numNCnt = firstSort(numNCnt);

	infile.close();

	for (int i = 0; i < numNCnt.size(); i++) {
		cout << numNCnt[i].first << ":" << numNCnt[i].second << endl;
	}

	return 0;
}