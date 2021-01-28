#include <iostream>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int K, value, sum = 0;
    stack<int> s;
    cin >> K;

    for (int i = 0; i < K; i++) {
        cin >> value;
        if (value == 0) {
            sum -= s.top();
            s.pop();
        }

        else {
            sum += value;
            s.push(value);
        }
    }

    cout << sum;
    return 0;
}