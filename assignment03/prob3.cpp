#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
#include <algorithm>
using namespace std;

vector<string> words, lines;
vector<vector<int>> lineNums;

vector<string> split_line(string line, char delimiter) {
	vector<string> tokens;
	stringstream sstream(line);
	string str;

	while (getline(sstream, str, delimiter))
		tokens.push_back(str);

	return tokens;
}

string trim(string str) {
	int s = 0, t = str.length() - 1;
	
	while (s < str.length() && !isalpha(str[s]))
		s++;
	while (t >= 0 && !isalpha(str[t]))
		t--;

	if (s <= t)
		return str.substr(s, t - s + 1);
	else
		return "";
}

int findWord(string word) {
	for (int i = 0; i < words.size(); i++)
		if (words[i] == word)
			return i;
	return -1;
}

void addWord(string word, int lineNum) {
	int index = findWord(word);
	
	if (index > -1)
		lineNums[index].push_back(lineNum);
	else {
		words.push_back(word);
		sort(words.begin(), words.end());
		int indexTmp = findWord(word);
		vector<int> tmp = { lineNum };
		lineNums.insert(lineNums.begin() + indexTmp, tmp);
	}
}

string makeLower(string s) {
	for (int i = 0; i < s.length(); i++)
		s[i] = tolower(s[i]);
	return s;
}

vector<int> eraseDuple(vector<int> v1) {
	for (int i = 0; i < v1.size() - 1; i++) {
		if (v1[i] == v1[i + 1])
			v1.erase(v1.begin() + i + 1);
	}
	return v1;
}

void makeIndex(string fileName) {
	ifstream theFile(fileName);
	int lineNum = 0;
	string line;
	while (getline(theFile, line)) {
		lines.push_back(line);
		vector<string> tokens = split_line(line, ' ');

		for (auto s : tokens){
			s = trim(s);
			if (s.length() >= 3) {
				s = makeLower(s);
				addWord(s, lineNum);
			}
		}
		lineNum++;
	}
	theFile.close();
}

void handle_find(string keyword) {
	keyword = makeLower(keyword);
	int index = findWord(keyword);

	if (index != -1) {
		cout << "The word " << keyword << " appears " <<
			lineNums[index].size() << " times in lines: ";
		cout << endl;
		for (auto v : eraseDuple(lineNums[index]))
			cout << v << ": " << lines[v] << endl;
	}
	else
		cout << "The word " << keyword << " doesn't appear." << endl;

}

int main() {
	string command;
	
	while (true) {
		cout << "$ ";
		cin >> command;
		if (command == "read") {
			string fileName;
			cin >> fileName;
			makeIndex(fileName);
		}
		else if (command == "find") {
			string keyword;
			cin >> keyword;
			handle_find(keyword);
		}
		else if (command == "exit")
			break;
	}
	
	return 0;
}