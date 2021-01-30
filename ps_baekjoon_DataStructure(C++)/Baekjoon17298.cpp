#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    stack<int> index;
    int N;
    cin >> N;

    int* ans = new int[N];
    int* num = new int[N];
    for (int i = 0; i < N; i++) {
        ans[i] = -1;
    }

    for (int i = 0; i < N; i++) {
        cin >> num[i];
    }

    for (int i = 0; i < N; i++) {
        while(!index.empty() && num[index.top()] < num[i]) {
            ans[index.top()] = num[i];
            index.pop();
        }

        index.push(i);
    }

    for (int i = 0; i < N; i++) {
        cout << ans[i] << " ";
    }

    delete ans;
    delete num;
    return 0;
}