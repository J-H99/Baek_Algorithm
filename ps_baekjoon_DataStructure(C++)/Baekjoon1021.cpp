#include <iostream>
#include <deque>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, V, idx, check = 0;
    cin >> N >> M;

    deque<int> deq;
    for (int i = 1; i <= N; i++) {
        deq.push_back(i);
    }

    for (int i = 0; i < M; i++) {
        cin >> V;

        for (int j = 0; j < deq.size(); j++) {
            if (deq[j] == V) {
                idx = j;
                break;
            }
        }

        if (2 * idx <= deq.size()) {
            for (int j = 0; j < idx; j++) {
                deq.push_back(deq.front());
                deq.pop_front();
                check++;
            }
            deq.pop_front();
        }
        
        else {
            for (int j = 0; j < deq.size() - idx; j++) {
                deq.push_front(deq.back());
                deq.pop_back();
                check++;
            }
            deq.pop_front();
        }
    }

    cout << check;
    return 0;
}