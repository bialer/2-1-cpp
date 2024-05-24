#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> board;

int ch1(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	x--;
	y--;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		x--;
		y--;
	}
	return 0;
}

void turn1(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		x--;
		y--;
	}
}

int ch2(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	y--;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		y--;
	}
	return 0;
}

void turn2(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		y--;
	}
}

int ch3(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	x++;
	y--;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		x++;
		y--;
	}
	return 0;
}

void turn3(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		x++;
		y--;
	}
}

int ch4(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	x++;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		x++;
	}
	return 0;
}

void turn4(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		x++;
	}
}

int ch5(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	x++;
	y++;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		x++;
		y++;
	}
	return 0;
}

void turn5(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		x++;
		y++;
	}
}

int ch6(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	y++;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		y++;
	}
	return 0;
}

void turn6(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		y++;
	}
}

int ch7(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	x--;
	y++;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		x--;
		y++;
	}
	return 0;
}

void turn7(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		x--;
		y++;
	}
}

int ch8(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] == 3 - color) return 0;
	x--;
	while (x >= 0 && x <= 7 &&
		y >= 0 && y <= 7) {
		if (board[y][x] == 0) return 0;
		else if (board[y][x] == color) return cnt;
		cnt++;
		x--;
	}
	return 0;
}

void turn8(int x, int y, int color) {
	board[y][x] = 0;
	while (board[y][x] != color) {
		board[y][x] = color;
		x--;
	}
}

void printBoard() {
	for (auto a : board) {
		for (auto b : a)
			cout << b << " ";
		cout << endl;
	}
	cout << endl;
}

int countStoneToCapture(int x, int y, int color) {
	int cnt = 0;
	if (board[y][x] != 0) return -1;
	if (color == 1) {
		if (ch1(x, y, 1) > 0) cnt += ch1(x, y, 1);
		if (ch2(x, y, 1) > 0) cnt += ch2(x, y, 1);
		if (ch3(x, y, 1) > 0) cnt += ch3(x, y, 1);
		if (ch4(x, y, 1) > 0) cnt += ch4(x, y, 1);
		if (ch5(x, y, 1) > 0) cnt += ch5(x, y, 1);
		if (ch6(x, y, 1) > 0) cnt += ch6(x, y, 1);
		if (ch7(x, y, 1) > 0) cnt += ch7(x, y, 1);
		if (ch8(x, y, 1) > 0) cnt += ch8(x, y, 1);
	}
	else if (color == 2) {
		if (ch1(x, y, 2) > 0) cnt += ch1(x, y, 2);
		if (ch2(x, y, 2) > 0) cnt += ch2(x, y, 2);
		if (ch3(x, y, 2) > 0) cnt += ch3(x, y, 2);
		if (ch4(x, y, 2) > 0) cnt += ch4(x, y, 2);
		if (ch5(x, y, 2) > 0) cnt += ch5(x, y, 2);
		if (ch6(x, y, 2) > 0) cnt += ch6(x, y, 2);
		if (ch7(x, y, 2) > 0) cnt += ch7(x, y, 2);
		if (ch8(x, y, 2) > 0) cnt += ch8(x, y, 2);
	}

	return cnt;
}

bool turnStone(int x, int y, int color) {
	bool able = false;
	if (ch1(x, y, color) != 0) {
		turn1(x, y, color);
		able = true;
	}
	if (ch2(x, y, color) != 0) {
		turn2(x, y, color);
		able = true;
	}
	if (ch3(x, y, color) != 0) {
		turn3(x, y, color);
		able = true;
	}
	if (ch4(x, y, color) != 0) {
		turn4(x, y, color);
		able = true;
	}
	if (ch5(x, y, color) != 0) {
		turn5(x, y, color);
		able = true;
	}
	if (ch6(x, y, color) != 0) {
		turn6(x, y, color);
		able = true;
	}
	if (ch7(x, y, color) != 0) {
		turn7(x, y, color);
		able = true;
	}
	if (ch8(x, y, color) != 0) {
		turn8(x, y, color);
		able = true;
	}

	return able;
}

bool checkAbleGame(int color) {
	int maxCnt = 0;
	bool f = false;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int tmpCnt = 0;
			tmpCnt = countStoneToCapture(j, i, color);
			if (tmpCnt > maxCnt)
				maxCnt = tmpCnt;
		}
	}
	if (maxCnt == 0) f = true;
	return f;
}

void turnHuman(bool& f1) {
	int x, y, maxCnt = 0;
	cin >> x >> y;

	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int tmpCnt = 0;
			tmpCnt = countStoneToCapture(j, i, 1);
			if (tmpCnt > maxCnt)
				maxCnt = tmpCnt;
		}
	}

	if (maxCnt == 0) {
		f1 = true;
		return;
	}

	if (turnStone(x, y, 1) == false) {
		cout << "불가능" << endl;
		turnHuman(f1);
	}
	else {
		turnStone(x, y, 1);
	}

}

void turnComputer(bool& f2) {
	int max_x, max_y, maxCnt = 0;
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) {
			int tmpCnt = 0;
			tmpCnt = countStoneToCapture(j, i, 2);
			if (tmpCnt > maxCnt) {
				maxCnt = tmpCnt;
				max_x = j;
				max_y = i;
			}
		}
	}
	if (maxCnt == 0) {
		f2 = true;
		return;
	}
	turnStone(max_x, max_y, 2);

	printBoard();
}

int main() {
	for (int i = 0; i < 8; i++) {
		vector<int> tmpLine;
		for (int j = 0; j < 8; j++)
			tmpLine.push_back(0);
		board.push_back(tmpLine);
	}

	board[3][3] = 2;
	board[3][4] = 1;
	board[4][4] = 2;
	board[4][3] = 1;

	printBoard();

	while (true) {
		bool f1 = false, f2 = false;

		cout << "x, y 입력: ";
		turnHuman(f1);
		printBoard();

		cout << "컴퓨터" << endl;
		turnComputer(f2);

		if (checkAbleGame(1) &&
			checkAbleGame(2)) break;
	}

	printBoard();

	return 0;
}