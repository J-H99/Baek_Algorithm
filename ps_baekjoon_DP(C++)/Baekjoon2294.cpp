#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int infi = 987654321;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    int n, k;
    cin >> n >> k;

    int* cost = new int[n + 1];
    int* DP = new int[k + 1];

    cost[0] = DP[0] = 0;
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    for (int i = 1; i <= k; i++) {
        DP[i] = infi;
    }

    sort(cost, cost + n, compare);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - cost[i] >= 0) {
                DP[j] = min(DP[j], DP[j - cost[i]] + 1);
            }
        }
    }
    
    if (DP[k] == infi) {
        DP[k] = -1;
    }
    cout << DP[k];
    delete cost;
    delete DP;
    return 0;
}