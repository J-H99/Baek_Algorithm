#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int* cost = new int[n+1];
    int* DP = new int[k+1];

    memset(DP, 0, sizeof(int) * (k+1));
    for (int i = 1; i <= n; i++) {
        cin >> cost[i];
    }

    DP[0] = 1;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= k; j++) {
            if (j - cost[i] >= 0) {
                DP[j] += DP[j - cost[i]];
            }
        }
    }    

    cout << DP[k];
    return 0;
}  