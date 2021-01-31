#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int* p = new int[N + 1];
    int* DP = new int[N + 1];
    for (int i = 1; i <= N; i++) {
        cin >> p[i];
        DP[i] = 987654321;
    }

    DP[0] = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = i; j <= N; j++) {
            DP[j] = min(DP[j], DP[j - i] + p[i]);
        }
    }

    cout << DP[N];
    delete p;
    delete DP;
    return 0;
}