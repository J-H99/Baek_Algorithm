#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    int* arr = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, compare);

    for (int i = 0; i < N; i++) {
        cout << arr[i] << "\n";
    }
    return 0;
}