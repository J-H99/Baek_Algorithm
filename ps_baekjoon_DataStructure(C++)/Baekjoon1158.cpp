#include <iostream>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, K;
    cin >> N >> K;

    queue<int> circular_que;
    for (int i = 1; i<= N; i++) {
        circular_que.push(i);
    }

    cout << "<";
    while(!circular_que.empty()) {
        for (int i = 0; i < K - 1; i++) {
            circular_que.push(circular_que.front());
            circular_que.pop();
        }
        cout << circular_que.front();
        circular_que.pop();

        if (!circular_que.empty()) {
            cout << ", ";
        } 
    }
    cout <<">";
    return 0;
}