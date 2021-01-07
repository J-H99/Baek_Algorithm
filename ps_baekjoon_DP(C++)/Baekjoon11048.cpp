#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    int** maze = new int*[N + 1];
    int** dp = new int*[N + 1];
    for (int i = 0; i <= N; i++) {
        maze[i] = new int[M + 1];
        dp[i] = new int[M + 1];
        memset(maze[i], 0, sizeof(int) * (M + 1));
        memset(dp[i], 0, sizeof(int) * (M + 1));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            cin >> maze[i][j];
        }
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= M; j++) {
            if (i == 1 && j == 1) {
                dp[i][j] = maze[i][j];
            }

            else if (i == 1 && j != 1) {
                dp[i][j] = dp[i][j-1] + maze[i][j];
            }

            else if (i != 1 && j == 1) {
                dp[i][j] = dp[i-1][j] + maze[i][j];
            }

            else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]) + maze[i][j];
            }
        }
    }

    cout << dp[N][M];
    for (int i = 0; i <= N; i++) {
        delete maze[i];
        delete dp[i];
    }
    delete maze;
    delete dp;
    return 0;
}