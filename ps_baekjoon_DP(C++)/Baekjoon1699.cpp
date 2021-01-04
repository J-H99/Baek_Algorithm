#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>

using namespace std;

int infi = 987654;
int main() {
    int N, pow_val;
    cin >> N;

    int* DP = new int[N + 1];
    memset(DP, infi, sizeof(int) * (N + 1));

    DP[1] = 1;
    if (N == 1) {
        cout << DP[1];
    }

    else {
        for (int i = 2; i <= N; i++) {
            for (int j = 1; j <= floor(sqrt(N)); j++) {
                pow_val = ceil(pow(j, 2));
                if (i == pow_val) {
                    DP[i] = 1;
                }

                else if (i - pow_val > 0) {
                    DP[i] = min(DP[i], DP[i - pow_val] + 1);
                }
            }
        }

        cout << DP[N];
    }
    delete DP;
    return 0;
}