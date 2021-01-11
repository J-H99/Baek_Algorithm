#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    int N;
    cin >> N;

    int* trivial_divisor = new int[N];
    
    for (int i = 0; i < N; i++) {
        cin >> trivial_divisor[i];
    }

    sort(trivial_divisor, trivial_divisor + N, compare);
    cout << trivial_divisor[0] * trivial_divisor[N - 1];
}