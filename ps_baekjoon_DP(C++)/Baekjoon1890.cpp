#include <iostream>
#include <cstring>

using namespace std;
using LL = long long;

int main() {
    int N;
    cin >> N;

    int** board = new int*[N];
    LL** DP = new LL*[N];

    for (int i = 0; i < N; i++) {
        board[i] = new int[N];
        DP[i] = new LL[N];
        memset(DP[i], 0, sizeof(LL) * N);
    }

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            cin >> board[i][j];
        }
    }

    DP[0][0] = 1;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (i == N - 1 && j == N - 1) {
                break;
            }

            if (j + board[i][j] < N && DP[i][j] != 0) {
                DP[i][j + board[i][j]] += DP[i][j];
            }

            if (i + board[i][j] < N && DP[i][j] != 0) {
                DP[i + board[i][j]][j] += DP[i][j];
            }
        }
    }

    cout << DP[N - 1][N - 1];
    for (int i = 0; i < N; i++) {
        delete board[i];
        delete DP[i];
    }
    delete board;
    delete DP;
    return 0;
}