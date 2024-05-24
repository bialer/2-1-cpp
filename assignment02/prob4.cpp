#include <iostream>
#include <string>
using namespace std;

int main() {
	string prob;
	int start = 0, area = 1, sum = 0;
	cin >> prob;

	for (int i = 0; i < prob.length() - 1; i++) {
		if (i == prob.length() - 2) {
			area++;
			string num = prob.substr(start, area);
			sum += stoi(num);
			break;
		}
		else if (prob[i + 1] == '+' || prob[i + 1] == '-') {
			string num = prob.substr(start, area);
			sum += stoi(num);
			start += area;
			area = 1;
		}
		else area++;
	}

	cout << sum << endl;
	
	return 0;
}