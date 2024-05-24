#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

double getDistance(int x1, int x2, int y1, int y2) {
	return sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
}

class MyPoint {
private:
	int x;
	int y;
public:
	MyPoint(int x1, int y1) {
		x = x1;
		y = y1;
	}

	int getX() { return x; }
	int getY() { return y; }

	bool getMaxDis(MyPoint other, double& maxDis) {
		if (getDistance(x, other.x, y, other.y) > maxDis) {
			maxDis = getDistance(x, other.x, y, other.y);
			return true;
		}
		return false;
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

	void put_point(vector<MyPoint>& points) {
		points.push_back(MyPoint(x_min, y_min));
		points.push_back(MyPoint(x_min, y_max));
		points.push_back(MyPoint(x_max, y_min));
		points.push_back(MyPoint(x_max, y_max));
	}
};

void read_input(istream& source, vector<Rect>& rects) {
	int x, y, w, h;
	while (source >> x >> y >> w >> h)
		rects.push_back(Rect(x, y, w, h));
}

int main() {
	int n, point1 = 0, point2 = 0;
	vector<Rect> rects;
	vector<MyPoint> points;
	ifstream infile("input2.txt");
	infile >> n;
	read_input(infile, rects);
	double maxDistance = 0;

	for (auto rect : rects)
		rect.put_point(points);

	for (int i = 0; i < points.size() - 1; i++) {
		for (int j = i + 1; j < points.size(); j++) {
			if (points[i].getMaxDis(points[j], maxDistance)) {
				point1 = i;
				point2 = j;
			}
		}
	}

	double centerX, centerY, rad;
	centerX = double(points[point1].getX() + points[point2].getX()) / 2.0;
	centerY = double(points[point1].getY() + points[point2].getY()) / 2.0;
	rad = maxDistance / 2.0;

	cout << centerX << " " << centerY << " " << rad << endl;

	return 0;
}