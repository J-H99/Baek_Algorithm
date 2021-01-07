#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, M, x, y;
    cin >> N >> M;

    int* friends = new int[N];
    for (int i = 0; i < N; i++) {
        friends[i] = 0;
    }

    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        friends[x - 1]++;
        friends[y - 1]++;
    }

    for (int i = 0; i < N; i++) {
        cout << friends[i] << "\n";
    }
    delete friends;
    return 0;
}