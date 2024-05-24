#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<pair<int, int>> road;

void move1(int x, int& y, int k) {
	int tmp_y;
	vector<pair<int, int>> tmpPair;

	tmp_y = y + k;

	for (int i = tmp_y; i > y; i--)
		tmpPair.push_back({ x, i });

	for (auto r : road) {
		for (auto t : tmpPair) {
			if (r.first == t.first) {
				if (r.second == t.second) {
					cout << "invalid move" << endl;
					return;
				}
			}
		}
	}

	for (auto t : tmpPair)
		road.push_back(t);
	y = tmp_y;
	cout << x << " " << y << endl;
}

void move2(int& x, int y, int k) {
	int tmp_x;
	vector<pair<int, int>> tmpPair;

	tmp_x = x + k;

	for (int i = tmp_x; i > x; i--)
		tmpPair.push_back({ i, y });

	for (auto r : road) {
		for (auto t : tmpPair) {
			if (r.first == t.first) {
				if (r.second == t.second) {
					cout << "invalid move" << endl;
					return;
				}
			}
		}
	}

	for (auto t : tmpPair)
		road.push_back(t);
	x = tmp_x;
	cout << x << " " << y << endl;
}

void move3(int x, int& y, int k) {
	int tmp_y;
	vector<pair<int, int>> tmpPair;

	tmp_y = y - k;

	for (int i = tmp_y; i < y; i++)
		tmpPair.push_back({ x, i });

	for (auto r : road) {
		for (auto t : tmpPair) {
			if (r.first == t.first) {
				if (r.second == t.second) {
					cout << "invalid move" << endl;
					return;
				}
			}
		}
	}

	for (auto t : tmpPair)
		road.push_back(t);
	y = tmp_y;
	cout << x << " " << y << endl;
}

void move4(int& x, int y, int k) {
	int tmp_x;
	vector<pair<int, int>> tmpPair;

	tmp_x = x - k;

	for (int i = tmp_x; i < x; i++)
		tmpPair.push_back({ i, y });

	for (auto r : road) {
		for (auto t : tmpPair) {
			if (r.first == t.first) {
				if (r.second == t.second) {
					cout << "invalid move" << endl;
					return;
				}
			}
		}
	}

	for (auto t : tmpPair)
		road.push_back(t);
	x = tmp_x;
	cout << x << " " << y << endl;
}

int main() {
	int x = 0, y = 0, tmp_x = 0, tmp_y = 0, n = 0, k = 0, cnt = 0;
	
	road.push_back(make_pair(x, y));

	while (n != -1 && k != -1) {
		cin >> n >> k;
		
		if (n == 0) move1(x, y, k);
		else if (n == 1) move2(x, y, k);
		else if (n == 2) move3(x, y, k);
		else if (n == 3) move4(x, y, k);
	}
	
	return 0;
}