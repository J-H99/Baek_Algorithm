#include <iostream>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    LL max_val = -1;
    LL* n = new LL[T];
    for (int i = 0; i < T; i++) {
        cin >> n[i];
        if (max_val < n[i]) {
            max_val = n[i];
        }
    }

    LL** DP = new LL*[max_val];
    for (LL i = 0; i < max_val; i++) {
        DP[i] = new LL[3];
        for (LL j = 0; j < 3; j++) {
            DP[i][j] = 0;
        }
    }

    DP[0][0] = 1;
    DP[1][1] = 1;
    DP[2][0] = 1;
    DP[2][1] = 1;
    DP[2][2] = 1;

    for (LL i = 3; i < max_val; i++) {
        DP[i][0] = (DP[i - 1][2] + DP[i - 1][1]) % 1000000009;
        DP[i][1] = (DP[i - 2][0] + DP[i - 2][2]) % 1000000009;
        DP[i][2] = (DP[i - 3][0] + DP[i - 3][1]) % 1000000009;
    }

    for (int i = 0; i < T; i++) {
        cout << (DP[n[i] - 1][0] + DP[n[i] - 1][1] + DP[n[i] - 1][2]) % 1000000009 << "\n";
    }

    for (LL i = 0; i < max_val; i++) {
        delete DP[i];
    }
    delete DP;
    delete n;
    return 0;
}