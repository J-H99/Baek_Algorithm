#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;
    
    int* sequence = new int[N + 1];
    int* dp_shortest = new int[N + 1];
    int* dp_longest = new int[N + 1];
    int* dp = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> sequence[i];
        dp_shortest[i] = 1;
        dp_longest[i] = 1;
        dp[i] = 0;
    }

    sequence[0] = dp_shortest[0] = dp_longest[0] = dp[0] = 0;

    for (int i = 1; i <= N; i++) {
        for (int i = 0; i <= N; i++) {
            dp_shortest[i] = 1;
            dp_longest[i] = 1;
        }


        for (int j = i; j <= N; j++) {
            for (int k = j - 1; k >= i; k--) {
                if (sequence[j] < sequence[k]) {
                    dp_shortest[j] = max(dp_shortest[j], dp_shortest[k] + 1);
                }
            }
        }
        dp[i] = *max_element(dp_shortest, dp_shortest + N + 1);

        for (int j = 1; j <= i; j++) {
            for (int k = j - 1; k >= 1; k--) {
                if (sequence[j] > sequence[k]) {
                    dp_longest[j] = max(dp_longest[j], dp_longest[k] + 1);
                }
            }
        }

        dp[i] += *max_element(dp_longest, dp_longest + N + 1);
    }

    cout << *max_element(dp, dp + N + 1) - 1;
    delete sequence;
    delete dp_shortest;
    delete dp_longest;
    delete dp;
    return 0;
}