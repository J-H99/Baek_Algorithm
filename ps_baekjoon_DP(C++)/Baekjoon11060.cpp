#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int* jump = new int[N];
    pair<bool, int>* DP = new pair<bool, int>[N];
    for (int i = 0; i < N; i++) {
        cin >> jump[i];

        DP[i].first = false;
        DP[i].second = 987654321;
    }

    DP[0].first = true;
    DP[0].second = 0;

    for (int i = 0; i < N; i++) {
        if (DP[i].first) {
            for (int j = i + 1; j <= i + jump[i] && j < N; j++) {
                if (!DP[j].first) {
                    DP[j].first = true;
                    DP[j].second = min(DP[j].second, DP[i].second + 1);
                }
            }
        }
    }

    if (!DP[N - 1].first) {
        cout << -1;
    } else {
        cout << DP[N - 1].second;
    }
    
    delete jump;
    delete DP;
    return 0;
}