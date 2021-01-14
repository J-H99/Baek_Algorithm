#include <iostream>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    
    int* DP = new int[N];
    if (N == 1) {
        cout << 3;
    }

    else if (N == 2) {
        cout << 7;
    }

    else {
        DP[0] = 3;
        DP[1] = 7;
        
        for (int i = 2; i < N; i++) {
            DP[i] = DP[i - 1] + 2 * DP[i - 2] + (DP[i - 1] - DP[i - 2]);
            DP[i] %= 9901;
        }

        cout << DP[N - 1];
    }
    
    delete DP;
    return 0;
}