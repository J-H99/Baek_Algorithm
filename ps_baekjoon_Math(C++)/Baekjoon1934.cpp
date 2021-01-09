#include <iostream>

using namespace std;
using LL = long long;

LL gcd(int A, int B) {
    if (B == 0) {
        return A;
    }

    if (A < B) {
        int temp = A;
        A = B;
        B = temp;
    }

    return gcd(B, A % B);
}

int main() {
    int T, A, B;
    cin >> T;

    LL* result = new LL[T];
    for (int i = 0; i < T; i++) {
        cin >> A >> B;
        result[i] = A * B / gcd(A, B);
    }

    for(int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    delete result;
    return 0;
}