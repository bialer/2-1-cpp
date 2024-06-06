#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
using namespace std;

class GameObject {
protected:
	int distance;
	int x, y;
public:
	GameObject(int startX, int startY, int distance) {
		this->x = startX; this->y = startY;
		this->distance = distance;
	}
	virtual ~GameObject() {};

	virtual void move() = 0;
	virtual char getShape() = 0;

	int getX() { return x; }
	int getY() { return y; }
	bool collide(GameObject* p) {
		if (this->x == p->getX() && this->y == p->getY())
			return true;
		else return false;
	}
};

class Human :public GameObject {
public:
	Human(int x, int y, int dis) :GameObject(x, y, dis) {}
	~Human() {};

	void move() override {
		string way;
		while (true) {
			cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) >> ";
			cin >> way;
			if (way == "a") {
				if (x != 0) {
					x -= distance;
					break;
				}
				else {
					cout << "불가능" << endl;
					continue;
				}
			}
			else if (way == "s") {
				if (y != 9) {
					y += distance;
					break;
				}
				else {
					cout << "불가능" << endl;
					continue;
				}
			}
			else if (way == "d") {
				if (y != 0) {
					y -= distance;
					break;
				}
				else {
					cout << "불가능" << endl;
					continue;
				}
			}
			else if (way == "f") {
				if (x != 19) {
					x += distance;
					break;
				}
				else {
					cout << "불가능" << endl;
					continue;
				}
			}
		}
	}

	char getShape() override {
		return 'H';
	}
};
class Monster :public GameObject {
public:
	Monster(int x, int y, int dis) :GameObject(x, y, dis) {}
	~Monster() {};

	void move() override {
		while (true) {
			int way = rand() % 4;
			if (way == 0) {
				if (x > 1) {
					x -= distance;
					break;
				}
				else {
					continue;
				}
			}
			else if (way == 1) {
				if (y < 8) {
					y += distance;
					break;
				}
				else {
					continue;
				}
			}
			else if (way == 2) {
				if (y > 1) {
					y -= distance;
					break;
				}
				else {
					continue;
				}
			}
			else if (way == 3) {
				if (x < 18) {
					x += distance;
					break;
				}
				else {
					continue;
				}
			}
		}
	}

	char getShape() override {
		return 'M';
	}
};

class Food :public GameObject {
public:
	Food(int x, int y, int dis) :GameObject(x, y, dis) {}
	~Food() {};

	void move() override {
		while (true) {
			int way = rand() % 4;
			if (way == 0) {
				if (x != 0) {
					x -= distance;
					break;
				}
				else {
					continue;
				}
			}
			else if (way == 1) {
				if (y != 9) {
					y += distance;
					break;
				}
				else {
					continue;
				}
			}
			else if (way == 2) {
				if (y != 0) {
					y -= distance;
					break;
				}
				else {
					continue;
				}
			}
			else if (way == 3) {
				if (x != 19) {
					x += distance;
					break;
				}
				else {
					continue;
				}
			}
		}
	}

	char getShape() override {
		return '@';
	}
};

class Game {
public:
	string board[10][20];
	Human* h = new Human(0, 0, 1);
	Monster* m = new Monster(7, 5, 2);
	Food* f = new Food(10, 8, 1);
	int foodMoveCnt = 0, foodStopCnt = 0;

	Game() {
		cout << "** Human의 Food 먹기 게임을 시작합니다.**" << endl;
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				board[i][j] = "-";
			}
		}
	}
	~Game() { delete h; delete m; delete f; }

	void putMark() {
		board[h->getY()][h->getX()] = h->getShape();
		board[m->getY()][m->getX()] = m->getShape();
		board[f->getY()][f->getX()] = f->getShape();
	}

	void eraseMarkLife() {
		board[h->getY()][h->getX()] = "-";
		board[m->getY()][m->getX()] = "-";
	}
	void eraseMarkFood() {
		board[f->getY()][f->getX()] = "-";
	}
	void showBoard() {
		for (int i = 0; i < 10; i++) {
			for (int j = 0; j < 20; j++) {
				cout << board[i][j];
			}
			cout << endl;
		}
	}

	void myGame() {
		while (true) {
			int n = rand() % 2;

			putMark();
			showBoard();
			eraseMarkLife();

			h->move();
			m->move();
			if (n == 0 && foodMoveCnt < 2) {
				eraseMarkFood();
				f->move();
				foodMoveCnt++;
			}
			else if (n == 1 && foodStopCnt < 3) foodStopCnt++;

			else if (foodStopCnt == 3 && foodMoveCnt < 2) {
				eraseMarkFood();
				f->move();
				foodMoveCnt++;
			}
			else if (foodMoveCnt == 2 && foodStopCnt < 3) foodStopCnt++;

			if (h->collide(m)) {
				putMark();
				board[h->getY()][h->getX()] = m->getShape();
				showBoard();
				cout << "Human is Loser..." << endl;
				break;
			}
			else if (h->collide(f)) {
				putMark();
				board[h->getY()][h->getX()] = h->getShape();
				showBoard();
				cout << "Human is Winner!" << endl;
				break;
			}
			else if (m->collide(f)) {
				putMark();
				board[m->getY()][m->getX()] = m->getShape();
				showBoard();
				cout << "Human is Loser..." << endl;
				break;
			}

			if (foodStopCnt + foodMoveCnt == 5) {
				foodStopCnt = 0;
				foodMoveCnt = 0;
			}
		}
	}
};

int main() {
	srand((unsigned int)time(NULL));
	Game* g = new Game();
	g->myGame();

	return 0;
}
