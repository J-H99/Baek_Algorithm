#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, k;
    cin >> n >> k;

    int** DP = new int*[n];
    for (int i = 0; i < n; i++) {
        DP[i] = new int[k];

        DP[i][0] = 1;
        for (int j = 1; j < k; j++) {
            DP[i][j] = 0;
        }
    }

    for (int i = 1; i < n; i++) {
        for (int j = 1; j < k; j++) {
            DP[i][j] = DP[i - 1][j - 1] + DP[i - 1][j];
        }
    }

    cout << DP[n - 1][k - 1];
    for (int i = 0; i < n; i++) {
        delete DP[i];
    }
    delete DP;
    return 0;
}