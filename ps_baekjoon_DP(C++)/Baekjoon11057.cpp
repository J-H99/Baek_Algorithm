#include <iostream>
#include <cstring>

using namespace std;

int DP[1000][10];
int main() {
    int N;
    cin >> N;

    memset(DP, 0, sizeof(DP));

    DP[0][0] = 1;
    for(int i = 1; i <= 9; i++) {
        DP[0][i] = 1;
        DP[0][0] += 1;
    }
    if (N > 1) {
        for (int i = 1; i < N; i++) {
            for (int j = 1; j <= 9; j++) {
                for (int k = j; k <= 9; k++) {
                    DP[i][j] += DP[i - 1][k];
                }
                DP[i][j] %= 10007;
                DP[i][0] += DP[i][j];
            }
        }

        for (int i = 0; i < N - 1; i++) {
            DP[N - 1][0] += DP[i][0];
        }
    }
   
    DP[N-1][0] %= 10007;

    cout << DP[N-1][0];
    return 0;
}