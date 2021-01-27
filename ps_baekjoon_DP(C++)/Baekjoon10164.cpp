#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, K;
    cin >> N >> M >> K;

    LL** DP = new LL*[N + 1];
    for (int i = 0; i <= N; i++) {
        DP[i] = new LL[M + 1];
        for (int j = 0; j <= M; j++) {
            DP[i][j] = 1;
        }
    }

    if (K == 0 || K == N * M) {
        for (int i = 2; i <= N; i++) {
            for (int j = 2; j <= M; j++) {
                DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
            }
        }

        // for (int i = 1; i <= N; i++) {
        //     for (int j = 1; j <= M; j++) {
        //         cout << DP[i][j];
        //     }
        //     cout << endl;
        // }
        cout << DP[N][M];
    } 
    
    else {
        if (K < M) { //첫 번째 줄
            for (int i = 2; i <= N; i++) {
                for (int j = K + 1; j <= M; j++) {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                }
            }

            cout << DP[N][M];
        } 

        else if (K % M == 1) {
            for (int i = K / M + 2; i <= N; i++) {
                for (int j = 2; j <= M; j++) {
                    DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                }
            }

            cout << DP[N][M];
        }

        else if (K == M) {
            cout << 1;
        }

        else { // 다음 줄
            int first_path, second_path;

            if (K % M == 0) {
                for (int i = 2; i <= (K / M); i++) {
                    for (int j = 2; j <= M; j++) {
                        DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                    }
                }
                
                cout << DP[K / M][M];
            }

            else {
                for (int i = 2; i <= (K / M + 1); i++) {
                    for (int j = 2; j <= (K % M); j++) {
                        DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                    }
                }
                first_path = DP[K / M + 1][K % M];
                DP[K / M + 1][K % M] = 1;

                for (int i = (K / M + 1) + 1; i <= N; i++) {
                    for (int j = K % M + 1; j <= M; j++) {
                        DP[i][j] = DP[i - 1][j] + DP[i][j - 1];
                    }
                }

                second_path = DP[N][M];
                cout << first_path * second_path;
            }
        }
    }

    for (int i = 0; i <= N; i++) {
        delete DP[i];
    }
    delete DP;
    return 0;
}