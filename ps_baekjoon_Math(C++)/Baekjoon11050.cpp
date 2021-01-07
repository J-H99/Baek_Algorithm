#include <iostream>

using namespace std;

int main() {
    int N, K, numerator = 1, denominator = 1;
    cin >> N >> K;

    for (int i = K; i >= 1; i--) {
        denominator *= i;
    }

    for (int i = N; K >= 1; i--, K--) {
        numerator *= i;
    }

    cout << numerator / denominator;
    return 0;
}