#include <iostream>
#include <cmath>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, cnt, a, b, value;
    cin >> T;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        
        value = 1;
        for (int j = 1; j <= b; j++) {
            value *= a;
            value %= 10;
        }

        if (value == 0) {
            result[i] = 10;
        }

        else {
            result[i] = value;
        }
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << "\n";
    }

    delete result;
    return 0;
}