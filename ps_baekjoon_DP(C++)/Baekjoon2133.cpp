#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* DP = new int[N + 1];
    DP[1] = 0;

    if (N == 1) {
        cout << 0;
    }

    else if (N == 2) {
        cout << 3;
    }

    else if (N == 4) {
        cout << 11;
    }

    else {
        DP[2] = 3;
        DP[4] = 11;
        for (int i = 6; i <= N; i += 2) {
            DP[i] = DP[i - 2] * 3;

            for (int j = i - 4; j >= 2; j -= 2) {
                DP[i] += DP[j] * 2;
            }

            DP[i] += 2;
        }

        cout << DP[N];
    }

    delete DP;
    return 0;
}