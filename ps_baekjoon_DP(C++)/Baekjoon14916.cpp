#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    int* DP = new int[n + 1];
    fill(DP, DP + (n + 1), -1);
    for (int i = 1; i <= n; i++) {
        if (i == 2 || i == 5) {
            DP[i] = 1;
        }

        else if (i >= 5) {
            if (DP[i - 2] != -1) {
                DP[i] = DP[i] != -1 ? min(DP[i], DP[i - 2] + 1) : DP[i - 2] + 1;
            }

            if (DP[i - 5] != -1) {
                DP[i] = DP[i] != -1 ? min(DP[i], DP[i - 5] + 1) : DP[i - 5] + 1;
            }
        }
    }

    cout << DP[n];
    delete DP;
    return 0;
}