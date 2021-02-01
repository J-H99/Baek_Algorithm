#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, W, max_value = - 1;
    cin >> T >> W;

    int* drop = new int[T + 1];
    for (int i = 1; i <= T; i++) {
        cin >> drop[i];
    }

    int** DP = new int*[T + 1];
    for (int i = 0; i <= T; i++) {
        DP[i] = new int[W + 1];
        memset(DP[i], 0, sizeof(int) * (W + 1));
    }

    if (drop[1] == 2) {
        DP[1][0] = DP[0][0];
        DP[1][1] = max(DP[0][1] + 1, DP[0][0] + 1);
    }

    else {
        DP[1][0] = DP[0][0] + 1;
        DP[1][1] = max(DP[0][0], DP[0][1]);
    }

    for (int i = 2; i <= T; i++) {
        if (drop[i] == 1) {
            DP[i][0] = DP[i - 1][0] + 1;
            for (int j = 1; j <= W && j <= i; j++) {
                if (j % 2 == 0) {
                    DP[i][j] = max(DP[i - 1][j - 1] + 1, DP[i - 1][j] + 1);
                }

                else {
                    DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
                }
            }
        }

        else {
            DP[i][0] = DP[i - 1][0];
            for (int j = 1; j <= W && j <= i; j++) {
                if (j % 2 == 0) {
                    DP[i][j] = max(DP[i - 1][j - 1], DP[i - 1][j]);
                }

                else {
                    DP[i][j] = max(DP[i - 1][j - 1] + 1, DP[i - 1][j] + 1);
                }
            }
        }
    }

    for (int i = 0; i <= W; i++) {
        if (DP[T][i] > max_value) {
            max_value = DP[T][i];
        }
    }

    cout << max_value;
    for (int i = 0; i <= T; i++) {
        delete DP[i];
    }
    delete DP;
    delete drop;
    return 0;
}