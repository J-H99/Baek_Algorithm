#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, T, P, j, maximum_value = 0;
    cin >> N;

    pair<int, int>* pair_arr = new pair<int, int>[N];
    int* dp = new int[N];
    for(int i = 0; i < N; i++) {
        cin >> T >> P;
        pair_arr[i].first = T;
        pair_arr[i].second = P;
        dp[i] = P;
    }

    for (int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if (i - j >= pair_arr[j].first) {
                dp[i] = max(dp[i], pair_arr[i].second + dp[j]);
            }
        }
    }
    
    for (int i = 0; i < N; i++) {
        if (maximum_value < dp[i] && i + pair_arr[i].first <= N) {
            maximum_value = dp[i];
        }
    }

    cout << maximum_value;
    delete pair_arr;
    delete dp;
    return 0;
}