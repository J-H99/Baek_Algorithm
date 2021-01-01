#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    int N;
    cin >> N;

    int* arr = new int[N];

    for(int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    sort(arr, arr + N, compare);

    cout << arr[0] << " " << arr[N-1];
    return 0;
}