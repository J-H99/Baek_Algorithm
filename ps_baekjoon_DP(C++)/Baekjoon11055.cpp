#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    int* sequence = new int[N + 1];
    int* dp = new int[N + 1];

    dp[0] = 0;
    for (int i = 1; i <= N; i++) {
        cin >> sequence[i];
        dp[i] = sequence[i];
    }

    dp[1] = sequence[1];
    for (int i = 1; i <= N; i++) {
        for (int j = i - 1; j >= 1; j--) {
            if (sequence[i] > sequence[j]) {
                dp[i] = max(dp[i], dp[j] + sequence[i]);
            }
        }
    }
    cout << *max_element(dp, dp + N + 1);
    delete sequence;
    delete dp;
    return 0;
}