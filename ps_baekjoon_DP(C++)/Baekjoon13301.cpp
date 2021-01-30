#include <iostream>

using namespace std;
using LL = long long;

int main() {
    int N;
    cin >> N;

    LL* DP = new LL[N];

    if (N == 1) {
        cout << 4;
    }

    else if (N == 2) {
        cout << 6;
    }

    else {
        DP[0] = 1;
        DP[1] = 1;
        for (int i = 2; i < N; i++) {
            DP[i] = DP[i - 1] + DP[i - 2];
        }

        cout << DP[N - 1] * 2 + (DP[N - 1] + DP[N - 2]) * 2;
    }

    delete DP;
    return 0;
}