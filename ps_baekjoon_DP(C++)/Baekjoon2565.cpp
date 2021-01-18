#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& x, const pair<int, int>& y) {
    return x.first < y.first;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, max_value = -1;
    cin >> N;

    pair<int, int>* A = new pair<int, int>[N];
    int* DP = new int[N];

    for (int i = 0; i < N; i++) {
        cin >> A[i].first >> A[i].second;
        DP[i] = 1;
    }

    sort(A, A + N, compare);

    for (int i = 1; i < N; i++) {
        for (int j = i -1; j >= 0; j--) {
            if (A[j].second < A[i].second) {
                DP[i] = max(DP[j] + 1, DP[i]);
            }
        }
    }

    cout << N - *max_element(DP, DP + N);
    delete A;
    delete DP;
    return 0;
}