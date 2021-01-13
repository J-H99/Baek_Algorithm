#include <iostream>

using namespace std;

int main() {
    int N, S, M, max_value = -1;
    cin >> N >> S >> M;

    int* diff = new int[N];
    bool** DP = new bool*[N];
    
    for (int i = 0; i < N; i++) {
        cin >> diff[i];
        DP[i] = new bool[M + 1];
        for (int j = 0; j <= M; j++) {
            DP[i][j] = false;
        }
    }

    if (S + diff[0] <= M) {
        DP[0][S + diff[0]] = true;
    }
    
    if (S - diff[0] >= 0) {
        DP[0][S - diff[0]] = true;
    }

    for (int i = 1; i < N; i++) {
        for (int j = 0; j <= M; j++) {
            if (DP[i - 1][j]) {
                if (j + diff[i] <= M) {
                    DP[i][j + diff[i]] = true;
                } 
                
                if (j - diff[i] >= 0) {
                    DP[i][j - diff[i]] = true;
                }
            }
        }
    }

    for (int i = 0; i <= M; i++) {
        if (DP[N - 1][i]) {
            if (max_value < i) {
                max_value = i;
            }
        }
    }
    
    cout << max_value;
    
    for (int i = 0; i < N; i++) {
        delete DP[i];
    }
    delete DP;
    delete diff;
    return 0;
}