#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& A, const pair<int, int>& B) {
    return A.first < B.first;
}

int main() {
    int N, K;
    cin >> N >> K;

    int* DP = new int[K + 1];
    memset(DP, 0, sizeof(int) * (K + 1));
    pair<int, int>* item = new pair<int, int>[N + 1];
    
    for (int i = 1; i <= N; i++) {
        cin >> item[i].first >> item[i].second;
    }

    for (int i = 1; i <= N; i++) {
        for (int j = K; j >= 1; j--) {
            if (item[i].first <= j) {
                DP[j] = max(DP[j - item[i].first] + item[i].second, DP[j]);
            }
        }
    }

    cout << DP[K];
    delete DP;
    delete item;
    return 0;
}