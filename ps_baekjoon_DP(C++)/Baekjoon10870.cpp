#include <iostream>

using namespace std;
using LL = long long;

int main() {

    int n;
    cin >> n;
    LL Fn, Fn_1 = 1, Fn_2 = 0;
    
    if (n == 0) {
        cout << 0;
    }
    
    else if (n == 1) {
        cout << 1;
    }

    else {
        for (int i = 2; i <= n; i++) {
            Fn = Fn_1 + Fn_2;
            Fn_2 = Fn_1;
            Fn_1 = Fn;
        }    
        cout << Fn;
    }
    
    return 0;
}