#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int* DP = new int[N + 4];
    DP[1] = 1;
    DP[2] = 2;
    DP[3] = 1;
    DP[4] = 1;

    for (int i = 5; i <= N; i++) {
        if (DP[i - 1] % 2 == 0 || DP[i - 3] % 2 == 0 || DP[i - 4] % 2 == 0) {
            DP[i] = 1;
        }

        else {
            DP[i] = 2;
        }
    }

    if (DP[N] % 2 == 0) {
        cout << "CY";
    }

    else {
        cout << "SK";
    }
    delete DP;
    return 0;
}