#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

class OrderdVecInt {
private:
	int capacity = 0, num = 0;
	int* arr = nullptr;
public:
	void insert(int k) {
		if (capacity == 0 && num == 0)
			capacity = 1;
		else if (num != 0 && capacity == num)
			capacity *= 2;

		int* tmp_arr = new int[capacity];

		for (int i = 0; i < num; i++)
			tmp_arr[i] = arr[i];

		tmp_arr[num++] = k;
		delete[] arr;
		arr = tmp_arr;

		bubbleSort();
	}

	void bubbleSort() {
		for (int i = num - 1; i > 0; i--) {
			for (int j = 0; j < i; j++) {
				if (arr[i] < arr[j]) {
					int tmp = arr[i];
					arr[i] = arr[j];
					arr[j] = tmp;
				}
			}
		}
	}

	int size() {
		return num;
	}

	int& operator[](int i) {
		return arr[i];
	}

	bool remove_by_val(int n) {
		int* tmp_arr = new int[num - 1];
		bool check = false;
		int cnt = 0;

		for (int i = 0; i < num; i++) {
			if (arr[i] == n) {
				check = true;
				break;
			}
		}

		if (check == false)
			return false;

		for (int i = 0; i < num; i++) {
			if (arr[i] == n) 
				continue;
			tmp_arr[cnt++] = arr[i];
		}
		num--;
		delete[] arr;
		arr = tmp_arr;

		return true;
	}

	bool remove_by_index(int n) {
		if (num <= n)
			return false;

		int* tmp_arr = new int[num - 1];
		int cnt = 0;

		for (int i = 0; i < num; i++) {
			if (i == n)
				continue;
			tmp_arr[cnt++] = arr[i];
		}
		num--;
		delete[] arr;
		arr = tmp_arr;

		return true;
	}
};

int main() {
	srand((unsigned int)time(NULL));
	int n, k;
	OrderdVecInt vec;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int k = rand() % 1000;
		vec.insert(k);
	}

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	if (vec.remove_by_val(vec[2]))
		cout << "Remove done" << endl;
	else
		cout << "Remove failed" << endl;

	if (vec.remove_by_index(4))
		cout << "RemoveIndex done" << endl;
	else cout << "RemoveIndex failed" << endl;

	for (int i = 0; i < vec.size(); i++)
		vec[i] -= 10;

	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << " ";
	cout << endl;

	return 0;
}