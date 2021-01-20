#include <iostream>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, N, M;
    cin >> T;

    LL* result = new LL[T];
    int DP[31][31] = { {-1, },};

    for (int i = 1; i <= 30; i++) {
        DP[i][i] = 1;
        DP[1][i] = i;
    }

    for(int i = 0; i < T; i++) {
        cin >> N >> M;

        if (N == 1) {
            result[i] = DP[1][M];
        }

        else {
            for (int j = 2; j <= N; j++) {
                for (int k = j + 1; k <= M; k++) {
                    DP[j][k] = DP[j][k - 1] + DP[j - 1][k - 1];
                }
            }

            result[i] = DP[N][M];
        }
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << "\n";
    }
    delete result;
}