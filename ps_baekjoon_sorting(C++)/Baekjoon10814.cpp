#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool compare(const pair<int, string>& x, const pair<int, string>& y) {
    // if (x.first == y.first) {
    //     return false;
    // }
    return x.first < y.first;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    pair<int, string>* users = new pair<int, string>[N];
    for (int i = 0; i < N; i++) {
        cin >> users[i].first >> users[i].second;
    }

    stable_sort(users, users + N, compare);

    for (int i = 0; i < N; i++) {
        cout << users[i].first << " " << users[i].second << "\n";
    }
    delete[] users;
    return 0;
}