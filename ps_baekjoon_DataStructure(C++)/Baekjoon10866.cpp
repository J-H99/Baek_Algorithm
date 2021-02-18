#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, value;
    string op;
    cin >> N;

    deque<int> deq;
    for (int i = 0; i < N; i++) {
        cin >> op;

        if (op == "push_front") {
            cin >> value;
            deq.push_front(value);
        }
        
        else if (op == "push_back") {
            cin >> value;
            deq.push_back(value);
        }

        else if (op == "pop_front") {
            if (deq.empty()) {
                cout << "-1\n";
            }

            else {
                cout << deq.front() << "\n";
                deq.pop_front();
            }
        }

        else if (op == "pop_back") {
            if (deq.empty()) {
                cout << "-1\n";
            }

            else {
                cout << deq.back() << "\n";
                deq.pop_back();
            }
        }

        else if (op == "size") {
            cout << deq.size() << "\n";
        }

        else if (op == "empty") {
            if (deq.empty()) {
                cout << "1\n";
            }

            else {
                cout << "0\n";
            }
        }

        else if (op == "front") {
            if (deq.empty()) {
                cout << "-1\n";
            }

            else {
                cout << deq.front() << "\n";
            }
        }

        else if (op == "back") {
            if (deq.empty()) {
                cout << "-1\n";
            }

            else {
                cout << deq.back() << "\n";
            }
        }
    }

    return 0;
}