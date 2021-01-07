#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N, K;
    cin >> N >> K;

    int** dp = new int* [N + 1];
    for (int i = 0; i <= N; i++) {
        dp[i] = new int[K + 1];
        memset(dp[i], 0, sizeof(int)*(K + 1));
    }

    if (N == 1) {
        cout << 1;
        return 0;
    }

    else {
        dp[1][0] = 1;
        dp[1][1] = 1;
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= K; j++) {
                if (i == j) {
                    dp[i][j] = 1;
                }
                
                else if (j == 1) {
                    dp[i][j] = i;
                }

                else {
                    dp[i][j] = dp[i - 1][j - 1] + dp[i - 1][j];
                }
                
                dp[i][j] %= 10007;
            }
        }
    }

    cout << dp[N][K];
    for (int i = 0; i <= N; i++) {
        delete dp[i];
    }
    delete dp;
    return 0; 
}