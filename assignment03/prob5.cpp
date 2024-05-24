#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<vector<pair<int, int>>> lines;
vector<vector<int>> crossings;

void getLines(int N) {
	for (int i = 0; i < N; i++) {
		vector<pair<int, int>> line;
		int x, y;

		cin >> x >> y;
		line.push_back(make_pair(x, y));

		cin >> x >> y;
		line.push_back(make_pair(x, y));

		lines.push_back(line);
	}
}

bool dup(vector<pair<int, int>> line1, vector<pair<int, int>> line2) {
	if (line1[0].first == line1[1].first &&
		line2[0].first == line2[1].first) return false;
	else if (line1[0].second == line1[1].second &&
		line2[0].second == line2[1].second) return false;
	return true;
}

bool checkHorizon(vector<pair<int, int>> line) {
	if (line[0].second == line[1].second) return true;
	return false;
}

int intersect(vector<pair<int, int>> l1, vector<pair<int, int>> l2) {
	if (dup(l1, l2)) {
		if (checkHorizon(l1)) {
			if (l1[0].first <= l2[0].first && l2[0].first <= l1[1].first
				&& l2[0].second <= l1[0].second && l1[0].second <= l2[1].second)
				return 1;
		}
		else {
			if (l2[0].first <= l1[0].first && l1[0].first <= l2[1].first
				&& l1[0].second <= l2[0].second && l2[0].second <= l1[1].second)
				return 2;
		}
	}
	return 0;
}

void getCrossing(vector<pair<int, int>> l1, vector<pair<int, int>> l2) {
	vector<int> crossing;
	int n = intersect(l1, l2);

	if (n == 1) {
		crossing.push_back(l2[0].first);
		crossing.push_back(l1[0].second);
	}
	else if (n == 2) {
		crossing.push_back(l1[0].first);
		crossing.push_back(l2[0].second);
	}
	if (!(crossing.empty()))
		crossings.push_back(crossing);
}

int main() {
	int N;
	cin >> N;

	getLines(N);

	for (int i = 0; i < N - 1; i++) {
		for (int j = i + 1; j < N; j++) {
			getCrossing(lines[i], lines[j]);
		}
	}

	sort(crossings.begin(), crossings.end());

	for (int i = 0; i < crossings.size(); i++) {
		cout << "[" << crossings[i][0] << ", "
			<< crossings[i][1] << "]" << endl;
	}

	return 0;
}