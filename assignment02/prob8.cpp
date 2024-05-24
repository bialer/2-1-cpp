#include <iostream>
#include <string>
#include <vector>
using namespace std;

string findPrefix(vector<string> words) {
    if (words.empty()) return "";

    string prefix = words[0];
    for (int i = 1; i < words.size(); i++) {
        string word = words[i];
        int j = 0;

        while (j < prefix.length() && j < word.length()
            && prefix[j] == word[j]) j++;

        prefix = prefix.substr(0, j);
        if (prefix.empty()) return "";
    }
    return prefix;
}

int main() {
	int n;
	string str;
	vector<string> words;
    cin >> n;
    cin.ignore();

	for (int i = 0; i < n; i++) {
		getline(cin, str);
		words.push_back(str);
	}

    string prefix = findPrefix(words);

    if (prefix.empty()) cout << "noting" << endl;
    else cout << prefix << endl;
	
	return 0;
}