#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, val;
    cin >> N;

    int number[10000] = {0, };
    for (int i = 0; i < N; i++) {
        cin >> val;
        number[val - 1]++;
    }

    for (int i = 0; i < 10000; i++) {
        for (int j = 0; j < number[i]; j++) {
            cout << i + 1 << "\n";
        }
    }
}