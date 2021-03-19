#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    LL N, max_value = -1;
    cin >> N;

    LL* T = new LL[N];
    LL* P = new LL[N];
    LL* DP = new LL[N + 1];

    for (LL i = 0; i < N; i++) {
        cin >> T[i] >> P[i];
        DP[i] = 0;
    }

    DP[N] = 0;
    DP[0] = P[0];
    for (LL i = N - 1; i >= 0; i--) {
        if (i + T[i] > N) {
            DP[i] = DP[i + 1];
        }

        else {
            DP[i] = max(DP[i + 1], DP[i + T[i]] + P[i]);
        }
    }


    cout << *max_element(DP, DP + N + 1);
    delete T;
    delete P;
    delete DP;
    return 0;
}