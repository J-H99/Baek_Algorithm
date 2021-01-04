#include <iostream>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* DP = new int[N];
    if (N == 1) {
        cout << 1;
    }

    else if (N == 2) {
        cout << 2;
    }

    else {
        DP[0] = 1;
        DP[1] = 2;

        for (int i = 2; i < N; i++) {
            DP[i] = DP[i-1] + DP[i-2];
            DP[i] %= 15746;
        }

        cout << DP[N-1];
    }
    
    delete DP;
    return 0;
}