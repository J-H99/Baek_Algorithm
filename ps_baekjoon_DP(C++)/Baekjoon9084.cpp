#include <iostream>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, N, value;
    cin >> T;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> N;
        int* cost = new int[N + 1];
        for (int i = 0; i < N; i++) {
            cin >> cost[i];
        }

        cin >> value;

        int* DP = new int[value + 1];
        memset(DP, 0 , sizeof(int) * (value + 1));
        DP[0] = 1;

        for (int i = 0; i < N; i++) {
            for (int j = 1; j <= value; j++) {
                if (j - cost[i] >= 0) {
                    DP[j] += DP[j - cost[i]];
                }
            }
        }

        result[i] = DP[value];
        delete cost;
        delete DP;
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << "\n";
    }
    delete result;
    return 0;
}