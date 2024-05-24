#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void printMean(string str, vector<pair<string, string>> vp1) {
	vector<string> words;
	for (int i = 0; i < vp1.size(); i++)
		words.push_back(vp1[i].first);
	for (int i = 0; i < words.size(); i++) {
		if (str == words[i]) {
			cout << "Found:" << endl;
			cout << vp1[i].first << ": " << vp1[i].second << endl;
			break;
		}
		else if (i == 0 && str < words[i]) {
			cout << "Not found" << endl;
			cout << "+ " << vp1[i].first << ": " << vp1[i].second << endl;
			break;
		}
		else if (i == words.size() - 1 && str > words[i]) {
			cout << "Not found" << endl;
			cout << "- " << vp1[i].first << ": " << vp1[i].second << endl;
			break;
		}
		else if (i > 0 && words[i - 1] < str && str < words[i]) {
			cout << "Not found" << endl;
			cout << "- " << vp1[i - 1].first << ": " << vp1[i - 1].second << endl;
			cout << "+ " << vp1[i].first << ": " << vp1[i].second << endl;
			break;
		}
	}
}

void printPrefix(string str, vector<pair<string, string>> vp1) {
	cout << endl << "Results of prefix search:" << endl;
	
	vector<string> words;
	for (int i = 0; i < vp1.size(); i++)
		words.push_back(vp1[i].first);
	for (int i = 0; i < words.size(); i++) {
		if (words[i].substr(0, str.size()) == str)
			cout << vp1[i].first << ": " << vp1[i].second << endl;
	}
}

int main() {
	ifstream infile("shuffled_dict.txt");
	vector<pair<string, string>> wordDict;
	string str, line;

	getline(cin, str);

	while (getline(infile, line) && line.find('\t') != string::npos) {
			int tab = line.find('\t');
			if (tab != line.size() - 1){
				string word = line.substr(0, tab);
				string mean = line.substr(tab + 1, line.size() - tab);
				wordDict.push_back({ word, mean });
			}
	}

	sort(wordDict.begin(), wordDict.end());
	printMean(str, wordDict);
	printPrefix(str, wordDict);

	infile.close();
	
	return 0;
}