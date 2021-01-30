#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    LL max_val = -1;
    cin >> T;

    LL* tc = new LL[T];
    for (int i = 0; i < T; i++) {
        cin >> tc[i];
        if (max_val < tc[i]) {
            max_val = tc[i];
        }
    }
    
    LL* DP = new LL[max_val];
    DP[0] = 1;
    DP[1] = 2;
    DP[2] = 4;
    for (int i = 3; i < max_val; i++) {
        DP[i] = (DP[i - 1] + DP[i - 2] + DP[i - 3]) % 1000000009; 
    }

    for (int i = 0; i < T; i++) {
        cout << DP[tc[i] - 1] << "\n";
    }

    delete tc;
    delete DP;
    return 0;
}