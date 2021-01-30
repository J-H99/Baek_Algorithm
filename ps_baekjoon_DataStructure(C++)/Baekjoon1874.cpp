#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, val, j = 1;
    cin >> n;

    stack<int> s;
    vector<char> op;

    for (int i = 0; i < n; i++) {
        cin >> val;

        if (s.empty()) {
            for(; j <= val; j++) {
                op.push_back('+');
                s.push(j);
            }
        }

        if (val == s.top()) {
            op.push_back('-');
            s.pop();
            continue;
        }

        else {
            for (; j <= val; j++) {
                op.push_back('+');
                s.push(j);
            }

            if (val == s.top()) {
                op.push_back('-');
                s.pop();
            }

            else {
                cout << "NO";
                return 0;
            }
        }
    }

    for (auto i = op.begin(); i < op.end(); i++) {
        cout << *i << "\n";
    }
    return 0;
}