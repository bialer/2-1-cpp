#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<string> strToVec(string str, vector<string> v1) {
	string strTmp = "";
	for (int i = 0; i < str.length(); i++) {
		if (str[i] != ' ')
			strTmp += str[i];
			if (str[i + 1] == ' ' || i == str.length() - 1) {
			v1.push_back(strTmp);
			strTmp = "";
		}
	}
	return v1;
}

string makePureWord(string str) {
	int start = 0, end = str.length() - 1;
	string pureWord;
	while (start < str.length() && !isalnum(str[start]))
		start++;
	while (end >= 0 && !isalnum(str[end]))
		end--;
	if (start <= end) {
		pureWord = str.substr(start, end - start + 1);

		for (int i = 0; i < pureWord.length(); i++) 
			pureWord[i] = tolower(pureWord[i]);
	}
	return pureWord;
}

int main() {
	ifstream infile("sample.txt");
	vector<string> words, answerVec;
	string word, line;

	while (getline(infile, line)) {
		if (!line.empty()) {
			words = strToVec(line, words);
		}
	}

	for (int i = 0; i < words.size(); i++)
		words[i] = makePureWord(words[i]);

	answerVec.push_back(words[0]);

	for (int i = 1; i < words.size(); i++) {
		for (int j = 0; j < answerVec.size(); j++) {
			if (words[i] == answerVec[j]) break;
			else if (j == answerVec.size() - 1) {
				answerVec.push_back(words[i]);
				break;
			}
		}
	}

	sort(answerVec.begin(), answerVec.end());

	infile.close();

	for (auto k : answerVec)
		cout << k << " ";

	return 0;
}