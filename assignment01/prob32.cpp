#include <iostream>

using namespace std;
const int MAX = 100;

int main() {
    int N, num_0 = 0, left = 0, max_1 = 0;
    int arr[MAX];
    cin >> N;

    for (int i = 0; i < N; i++) cin >> arr[i];

    for (int i = 0; i < N; i++) {
        if (arr[i] == 0) num_0++;
        while (num_0 > 1){
            if (arr[left] == 0) num_0--;
            left++;
        }

        max_1 = max(max_1, i - left + 1);
    }

    cout << "가장 긴 연속된 1의 개수: " << max_1 << endl;

    return 0;
}
