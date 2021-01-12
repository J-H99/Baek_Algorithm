#include <iostream>

using namespace std;
using LL = long long;

int main() {
    LL N;
    cin >> N;

    int divisor = 2;

    while(N != 1) {
        if (N  % divisor == 0) {
            N /= divisor;
            cout << divisor << endl;
        }

        else {
            divisor++;
        }
    }
    return 0;
}