#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, max_inc = 1, max_dec = 1;
    cin >> N;

    int* sequence = new int[N];
    int** DP = new int*[N];
    for (int i = 0; i < N; i++) {
        cin >> sequence[i];
        DP[i] = new int[2];
        DP[i][0] = 1;
        DP[i][1] = 1;
    }

    for (int i = 0; i < N - 1; i++) {
        if (sequence[i] <= sequence[i + 1]) {
            DP[i + 1][0] = DP[i][0] + 1;

            if (max_inc < DP[i + 1][0]) {
                max_inc = DP[i + 1][0];
            }
        }

        if (sequence[i] >= sequence[i + 1]) {
            DP[i + 1][1] = DP[i][1] + 1;

            if (max_dec < DP[i + 1][1]) {
                max_dec = DP[i + 1][1];
            }
        }
    }

    cout << max(max_inc, max_dec);
    
    for (int i = 0; i < N; i++) {
        delete DP[i];
    }
    delete DP;
    delete sequence;
    return 0;
}