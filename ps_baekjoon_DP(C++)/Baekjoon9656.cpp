#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* DP = new int[N + 1];
    memset(DP, 0, sizeof(int) * (N + 1));

    DP[1] = 1;
    for (int i = 1; i <= N; i++) {
        if (i == 2) {
            DP[2] = 2;
        } 

        else if (i == 3) {
            DP[3] = 1;
        }

        else if (i % 3 != 0) {
            DP[i] = DP[(i / 3) * 3] + i % 3;
        }

        else if (i % 3 == 0) {
            DP[i] = DP[((i - 1) / 3) * 3] + 1;
        }
    }

    if (DP[N] % 2 == 0) {
        cout << "SK";
    } 

    else {
        cout << "CY";
    }
    delete DP;
    return 0;
}