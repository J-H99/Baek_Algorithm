#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, N, M, importance, cnt, maxidx, max_value = -1;
    cin >> T;
    
    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cnt = 1;

        queue<pair<int, int>> q;
        priority_queue<int> imp;
        int* arr = new int[N];

        for (int j = 0; j < N; j++) {
            cin >> importance;
            imp.push(importance);
            q.push(make_pair(j, importance));   
        }

        while(true) {
            if(imp.top() == q.front().second) {
                if (q.front().first == M) {
                    result[i] = cnt;
                    break;
                }

                else {
                    cnt++;
                    imp.pop();
                    q.pop();
                }
            }

            else {
                q.push(q.front());
                q.pop();
            }
        }

        delete arr;
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << "\n";
    }

    delete result;
    return 0;
}