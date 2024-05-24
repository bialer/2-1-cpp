#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	string word;
	vector<string> words;
	
	getline(cin, word);
	words.push_back(word);
	cout << word << endl;
	while (true) {
		getline(cin, word);
		bool check = false;
		
		if (word == "exit") return 0;
		else {
			for (int i = 0; i < words.size(); i++) {
				if (word == words[i]) {
					cout << "duplicate" << endl;
					check = true;
					break;
				}
				else if (i == words.size() - 1) {
					words.push_back(word);
					break;
				}
			}
		}
		if (check) continue;
		sort(words.begin(), words.end());
		for (auto k : words) cout << k << " ";
		cout << endl;
	}

	return 0;
}