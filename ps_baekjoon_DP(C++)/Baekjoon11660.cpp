#include <iostream>
#include <cstring>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, value;
    cin >> N >> M;

    pair<pair<int, int>, pair<int, int>> point;
    LL* result = new LL[M];
    LL** DP = new LL*[N + 1];

    memset(result, 0, sizeof(LL) * M);
    for (int i = 0; i <= N; i++) {
        DP[i] = new LL[N + 1];
        memset(DP[i], 0, sizeof(LL) * (N + 1));
    }

    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            cin >> value;
            DP[i][j] = value + DP[i][j - 1];
        }
    }

    for (int i = 0; i < M; i++) {
        cin >> point.first.first >> point.first.second >> point.second.first >> point.second.second;

        for (int j = point.first.first; j <= point.second.first; j++) {
            result[i] += (DP[j][point.second.second] - DP[j][point.first.second - 1]);
        }
    }

    for (int i = 0; i < M; i++) {
        cout << result[i] << "\n";
    }

    for (int i = 0; i <= N; i++) {
        delete DP[i];
    }
    delete[] DP;
    delete[] result;
    return 0;
}