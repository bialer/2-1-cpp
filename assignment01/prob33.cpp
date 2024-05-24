#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX = 100;

int main() {
	srand((unsigned int)time(NULL));
	int N, x, y, direction;
	double esc = 0;
	int arr[MAX][MAX];
	cin >> N;
	
	

	for(int i = 0; i < 10000; i++){
		x = N / 2;
		y = N / 2;

		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) arr[i][j] = 0;
		}

		while(true){
			if (x == 0 || y == 0 ||
				x == N - 1 || y == N - 1) {
				esc++;
				break;
			}

			if (arr[x][y + 1] == -1 && arr[x][y - 1] == -1 &&
				arr[x + 1][y] == -1 && arr[x - 1][y] == -1) break;

			while (true) {
				direction = rand() % 4;
				if (direction == 0 && arr[x][y - 1] == 0) {
					y--;
					arr[x][y] = 1;
					break;
				}
				else if (direction == 1 && arr[x][y + 1] == 0) {
					y++;
					arr[x][y] = 1;
					break;
				}
				else if (direction == 2 && arr[x - 1][y] == 0) {
					x--;
					arr[x][y] = 1;
					break;
				}
				else if (direction == 3 && arr[x + 1][y] == 0) {
					x++;
					arr[x][y] = 1;
					break;
				}
			}
		}
	}

	cout << esc / 10000.0 << endl;

	return 0;
}