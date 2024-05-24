#include <iostream>
using namespace std;
const int MAX = 100;

void bubbleSort(int arr[], int cnt) {
    for (int i = 0; i < cnt - 1; ++i) {
        for (int j = 0; j < cnt - i - 1; ++j) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main() {
    int arr[MAX];
    int n, cnt = 0;
    bool check;

    while (true) {
        cin >> n;
        check = true;

        if (n == -1) {
            break;
        }

        for (int i = 0; i < cnt; i++) {
            if (arr[i] == n) {
                cout << "duplicate" << endl;
                check = false;
                break;
            }
        }
        if (check) {
            arr[cnt++] = n;
            bubbleSort(arr, cnt);
            for (int i = 0; i < cnt; i++) {
                cout << arr[i] << " ";
            }
            cout << endl;
        }
    }

    return 0;
}
