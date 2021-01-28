#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, temp;
    string op;
    stack<int> s;
    
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> op;
        if (op == "push") {
            cin >> temp;

            s.push(temp);
        }

        else if (op == "pop") {
            if (s.empty()) {
                cout << "-1" << "\n";
            }

            else {
                temp = s.top();
                s.pop();
                cout << temp << "\n";
            }
        }

        else if (op == "size") {
            cout << s.size() << "\n";
        }

        else if (op == "empty") {
            if (s.empty()) {
                cout << "1" << "\n";
            }

            else {
                cout << "0" << "\n";
            }
        }

        else if (op == "top") {
            if (s.empty()) {
                cout << "-1" << "\n";
            }

            else {
                cout << s.top() << "\n";
            }
        }
    }
    return 0;
}