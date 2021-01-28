#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& x, const pair<int, int>& y) {
    if (x.first != y.first) {
        return x.first < y.first;
    }
    return x.second < y.second;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    pair<int, int>* point = new pair<int, int>[N];
    for (int i = 0; i < N; i++) {
        cin >> point[i].first >> point[i].second;
    }

    sort(point, point + N, compare);
    for (int i = 0; i < N; i++) {
        cout << point[i].first << " " << point[i].second << "\n";
    }

    delete point;
    return 0;
}