#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

class Circle {
private:
	int x, y, r;
public:
	Circle(int a, int b, int c) {
		x = a;
		y = b;
		r = c;
	}
	
	int getX() { return x; }
	int getY() { return y; }
	int getR() { return r; }

	bool intersect(Circle* other) {
		double distance = sqrt((x - other->x) *
			(x - other->x) + (y - other->y) * (y - other->y));
		return distance <= (r + other->r);
	}

	double area() {
		return 3.141592 * r * r;
	}
};

class Rect {
private:
	int x_min, x_max, y_min, y_max;
public:
	Rect(int x1, int x2, int y1, int y2) {
		x_min = x1;
		x_max = x2;
		y_min = y1;
		y_max = y2;
	}

	int getXMin() { return x_min; }
	int getXMax() { return x_max; }
	int getYMin() { return y_min; }
	int getYMax() { return y_max; }

	double area() {
		return (x_max - x_min) * (y_max - y_min);
	}

	bool intersect(Circle* cir) {
		int nearX = max(x_min, min(cir->getX(), x_max));
		int nearY = max(y_min, min(cir->getY(), y_max));
		double distance = sqrt((cir->getX() - nearX) * (cir->getX() - nearX)
			+ (cir->getY() - nearY) * (cir->getY() - nearY));
		return distance <= cir->getR();
	}
};

int main() {
	int n;
	string str;
	vector<Rect*> rects;
	vector<Circle*> cirs;
	ifstream infile("input1.txt");

	getline(infile, str);
	n = stoi(str);

	for (int i = 0; i < n; i++) {
		string strTmp;
		vector<string> vec;
		getline(infile, str);
		stringstream sstream(str);

		while (getline(sstream, strTmp, ' ')) 
			vec.push_back(strTmp);

		if (vec[0] == "R")
			rects.push_back(new Rect(stoi(vec[1]), stoi(vec[2]),
				stoi(vec[3]), stoi(vec[4])));

		else if (vec[0] == "C")
			cirs.push_back(new Circle(stoi(vec[1]), stoi(vec[2]),
				stoi(vec[3])));
	}
	vector<string> vecTmp;
	string strTmp;
	getline(infile, str);
	stringstream sstream(str);

	while (getline(sstream, strTmp, ' '))
		vecTmp.push_back(strTmp);

	Circle* lastCircle = new Circle(stoi(vecTmp[0]), stoi(vecTmp[1]), stoi(vecTmp[2]));

	infile.close();

	vector<pair<pair<double, string>, vector<int>>> interShapes;

	for (auto rect : rects) {
		if (rect->intersect(lastCircle)){
			vector<int> v = { rect->getXMin(), rect->getXMax(),
				rect->getYMin(), rect->getYMax() };
			interShapes.push_back(make_pair(make_pair(rect->area(), "R"), v));
		}
	}

	for (auto cir : cirs) {
		if (cir->intersect(lastCircle)) {
			vector<int> v = { cir->getX(), cir->getY(), cir->getR() };
			interShapes.push_back(make_pair(make_pair(cir->area(), "C"), v));
		}
	}

	sort(interShapes.begin(), interShapes.end());

	for (auto shape : interShapes) {
		cout << shape.first.second << " ";
		for (auto n : shape.second)
			cout << n << " ";
		cout << endl;
	}

	for (auto rect : rects) delete rect;
	for (auto cir : cirs) delete cir;
	delete lastCircle;

	return 0;
}