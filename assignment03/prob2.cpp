#include <iostream>
#include <vector>
using namespace std;

void compute_set(vector<int>& A, vector<int>& B) {
	for (int i = 0; i < B.size(); i++) {
		for (int j = 0; j < A.size(); j++) {
			if (B[i] == A[j]) {
				A.erase(A.begin() + j);
				break;
			}
			else if (j == 0 && B[i] < A[j]) {
				A.insert(A.begin(), B[i]);
				break;
			}
			else if (j != 0 && A[j - 1] < B[i] && B[i] < A[j]) {
				A.insert(A.begin() + j, B[i]);
				break;
			}
			else if (j == A.size() - 1 && A[j] < B[i]) {
				A.push_back(B[i]);
				break;
			}
		}
	}
}

int main() {
	int m, n, k;
	vector<int> first, second;
	cin >> m;

	for (int i = 0; i < m; i++) {
		cin >> k;
		first.push_back(k);
	}
	cin >> n;

	for (int i = 0; i < n; i++) {
		cin >> k;
		second.push_back(k);
	}

	compute_set(first, second);

	for (auto item : first)
		cout << item << " ";
	cout << endl;
	return 0;
}