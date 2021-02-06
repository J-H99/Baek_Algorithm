#include <iostream>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int D, K;
    cin >> D >> K;
    LL Fn, Fn_1 = 1, Fn_2 = 0;

    for (int i = 3; i < D; i++) {
        Fn = Fn_1 + Fn_2;
        Fn_2 = Fn_1;
        Fn_1 = Fn;
    }    
    
    Fn = Fn_1 + Fn_2;

    for (int i = 1;; i++) {
        if ((K - Fn_1 * i) % Fn == 0) {
            cout << i << "\n" << (K - Fn_1 * i) / Fn;
            break;
        }
    }

    return 0;
}