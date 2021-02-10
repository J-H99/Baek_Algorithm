#include <iostream>
#include <cstring>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    LL** DP = new LL*[N + 1];
    for (int i = 0; i <= N; i++) {
        DP[i] = new LL[K];
        memset(DP[i], 0, sizeof(LL) * K);
    }

    for (int i = 0; i <= N; i++) {
        DP[i][0] = 1;
    }

    for (int i = 0; i < K; i++) {
        DP[0][i] = 1;
    }

    for (int i = 1; i < K; i++) {
        for (int j = 1; j <= N; j++) {
            for (int k = 0; k <= j; k++) {
                DP[j][i] = (DP[j][i] + DP[k][i - 1]) % 1000000000;
            }
        }
    }
    
    cout << DP[N][K - 1];
    for (int i = 0; i <= N; i++) {
        delete DP[i];
    }
    delete DP;
    return 0;
}