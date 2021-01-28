#include <iostream>
#include <string>
#include <stack>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string parenthesis;
    int T;

    cin >> T;

    stack<char>* s = new stack<char>[T];
    for (int i = 0; i < T; i++) {
        parenthesis = "";
        cin >> parenthesis;
        for (int j = 0; j < parenthesis.length(); j++) {
            if (parenthesis[j] == '(') {
                s[i].push('(');
            }

            else if (parenthesis[j] == ')'){
                if (s[i].empty()) {
                    s[i].push('X');
                    break;
                }
                
                else {
                    s[i].pop();
                }
            }
        }
    }

    for (int i = 0; i < T; i++) {
        if (s[i].empty()) {
            cout << "YES" << "\n";
        }

        else {
            cout << "NO" << "\n";
        }
    }
    return 0;
}