#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int a, b, c;
    cin >> a >> b >> c;

    int DP[21][21][21] = { { {0, }, }, };

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 21; j++) {
            for (int k = 0; k < 21; k++) {
                if (i == 0 || j == 0 || k == 0) {
                    DP[i][j][k] = 1;
                }

                else if (i < j && j < k) {
                    DP[i][j][k] = DP[i][j][k - 1] + DP[i][j - 1][k - 1] - DP[i][j - 1][k];
                }

                else {
                    DP[i][j][k] = DP[i - 1][j][k] + DP[i - 1][j - 1][k] + DP[i - 1][j][k - 1] - DP[i -1][j - 1][k - 1];
                }
            }
        }
    }

    while (a != -1 || b != -1 || c != -1) {
        if (a <= 0 || b <= 0 || c <= 0) {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << DP[0][0][0] << "\n";
        }

        else if (a > 20 || b > 20 || c > 20) {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << DP[20][20][20] << "\n";
        }

        else {
            cout << "w(" << a << ", " << b << ", " << c << ") = " << DP[a][b][c] << "\n";           
        }

        cin >> a >> b >> c;
    }
    return 0;
}