#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& a, const pair<int, int>& b) {
    return a.first < b.first;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, cnt, N, score_second;
    cin >> T;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> N;
        cnt = 1;

        pair<int, int>* score = new pair<int, int>[N];
        for (int i = 0; i < N; i++ ) {
            cin >> score[i].first >> score[i].second;
        }
        
        sort(score, score + N, compare);

        score_second = score[0].second;
        for (int i = 1; i < N; i++) {
            if (score_second > score[i].second) {
                score_second = score[i].second;
                cnt++;
            }
        }

        result[i] = cnt;
        delete score;
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << "\n";
    }
    
    delete result;
    return 0;
}