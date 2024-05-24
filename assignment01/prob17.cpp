#include <iostream>
#include <cmath>
using namespace std;

int main() {
	int arr[100];
	int n;
	double avg, sum1 = 0, sum2 = 0, sd;
	cin >> n;

	for (int i = 0; i < n; i++) cin >> arr[i];
	for (int i = 0; i < n; i++) {
		sum1 += arr[i];
		avg = sum1 / n;
	}
	for (int i = 0; i < n; i++) {
		sum2 += (arr[i] - avg) * (arr[i] - avg);
	}
	sd = sqrt(sum2 / n);
	cout << avg << " " << sd << endl;
	
	return 0;
}