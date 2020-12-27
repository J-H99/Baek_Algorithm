#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int T, n;
    cin >> T;
    int* result = new int[T];

    for (int i = 0; i < T; i++) {
        cin >> n;

        int** score_arr = new int*[2];
        int** DP = new int*[2];
        for (int j = 0; j < 2; j++) {
            score_arr[j] = new int[n];
            DP[j] = new int[n];
        }

        for (int j = 0; j < n; j++) {
            cin >> score_arr[0][j];
        }

        for (int j = 0; j < n; j++) {
            cin >> score_arr[1][j];
        }

        /// Solving 
        DP[0][0] = score_arr[0][0];
        DP[1][0] = score_arr[1][0];

        if (n == 1) {
            result[i] = max(DP[0][0], DP[1][0]);
        }

        else if (n == 2) {
            result[i] = max(DP[0][0] + score_arr[1][1], DP[1][0] + score_arr[0][1]);
        }

        else {
            DP[0][1] = DP[1][0] + score_arr[0][1];
            DP[1][1] = DP[0][0] + score_arr[1][1];
            for(int k = 2; k < n; k++) {
                DP[0][k] = score_arr[0][k] + max(DP[1][k - 1], DP[1][k - 2]);
                DP[1][k] = score_arr[1][k] + max(DP[0][k - 1], DP[0][k - 2]);
            }
            result[i] = max(DP[0][n-1], DP[1][n-1]);
        }

        /// Solving

        for (int j = 0; j < 2; j++) {
            delete score_arr[j];
        }
        delete score_arr;
    }
    
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    return 0;
}