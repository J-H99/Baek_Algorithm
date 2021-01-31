#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    bool checker;
    string sentence;
    vector<bool> check;
    stack<char> parenthesis;

    getline(cin, sentence);
    while(sentence != ".") {
        checker = true;
        for (int i = 0; i < sentence.length(); i++) {
            if (sentence[i] == '(' || sentence[i] == '[') {
                parenthesis.push(sentence[i]);
            }

            else if (sentence[i] == ')') {
                if (parenthesis.empty()) {
                    check.push_back(false);
                    checker = false;
                    break;
                }

                else {
                    if (parenthesis.top() == '(') {
                        parenthesis.pop();
                    }

                    else {
                        check.push_back(false);
                        checker = false;
                        break;
                    }
                }
            }

            else if (sentence[i] == ']') {
                if (parenthesis.empty()) {
                    check.push_back(false);
                    checker = false;
                    break;
                }

                else {
                    if (parenthesis.top() == '[') {
                        parenthesis.pop();
                    }

                    else {
                        check.push_back(false);
                        checker = false;
                        break;
                    }
                }                
            }
        }

        if (checker && parenthesis.empty()) {
            check.push_back(true);
        }

        else if (checker && !parenthesis.empty()) {
            check.push_back(false);
        }

        while(!parenthesis.empty()) {
            parenthesis.pop();
        }

        getline(cin, sentence);
    }

    for (auto i = check.begin(); i != check.end(); i++) {
        if (*i == 1) {
            cout << "yes" << "\n";
        }

        else {
            cout << "no" << "\n";
        }
    }
    return 0;
}