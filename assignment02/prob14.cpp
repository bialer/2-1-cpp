#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> setWord(string line) {
	string word;
	vector<string> appWords;
	int start = 0, area = 0;

	while (!(line.find(' ', start) == string::npos
		&& line.find('\t', start) == string::npos)) {
		if (line.find(' ', start) < line.find('\t', start) ||
			line.find('\t', start) == string::npos)
			area = line.find(' ', start) - start;
		else if (line.find('\t', start) > line.find(' ', start))
			area = line.find('\t', start) - start;
		appWords.push_back(line.substr(start, area));
		start += area + 1;
	}
	appWords.push_back(line.substr(start, line.size() - start));

	for (int i = 0; i < appWords.size(); i++) {
		if (appWords[i].empty()) {
			appWords.erase(appWords.begin() + i);
			i--;
		}
	}
	return appWords;
}

vector<string> delDuple(vector<string> v1) {
	for (int i = 0; i < v1.size() - 1; i++) {
		if (v1[i] == v1[i + 1]) {
			v1.erase(v1.begin() + i);
			i--;
		}
	}
	return v1;
}

vector<string> setPrefixWord(string str, vector<string> v1) {
	vector<string> prefixWords;

	for (auto k : v1) {
		if (k.substr(0, str.length()) == str)
			prefixWords.push_back(k);
	}

	return prefixWords;
}

int main() {
	ifstream infile("harry.txt");
	vector<string> words;
	string line, word, str;

	while (getline(infile, line)) {
		if (!(line.empty())) {
			for (auto k : setWord(line))
				words.push_back(k);
		}
	}

	sort(words.begin(), words.end());
	cout << "로딩..." << endl;
	words = delDuple(words);

	cout << "입력: ";
	getline(cin, str);

	words = setPrefixWord(str, words);

	for (auto k : words) cout << k << endl;
	cout << words.size() << endl;

	infile.close();
	
	return 0;
}