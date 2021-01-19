#include <iostream>
#include <cstring>
#include <algorithm>
#include <stack>

using namespace std;

int main() {
    int N, cnt, maxval = -1, maxidx;
    stack<int> result;
    cin >> N;

    int* inp = new int[N];
    int* DP = new int[N];
    bool* checker = new bool[N];

    memset(checker, 0, sizeof(bool) * N);
    for (int i = 0; i < N; i++) {
        cin >> inp[i];
        DP[i] = 1;
    }

    for (int i = 1; i < N; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (inp[i] > inp[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    for (int i = 0; i < N; i++) {
        if (maxval < DP[i]) {
            maxval = DP[i];
            maxidx = i;
        }
    }

    cout << maxval << endl;
    for (int i = maxidx; i >= 0; i--) {
        if (DP[i] == maxval) {
            result.push(inp[i]);
            maxval--;
        }
    }

    while(!result.empty()) {
        cout << result.top() << " ";
        result.pop();
    }

    delete inp;
    delete DP;
    delete checker;
    return 0;
}