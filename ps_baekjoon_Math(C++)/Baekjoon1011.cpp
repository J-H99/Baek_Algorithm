#include <iostream>

using namespace std;
using LL = long long;

int main() {
    int T;
    LL x, y, diff, pow_num, base;
    cin >> T;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> x >> y;

        diff = y - x;
        base = 1;
        while(base*base < diff) {
            base++;
        }

        pow_num = base * base;
        if (pow_num == diff) {
            result[i] = 2 * base - 1;
        }

        else {
            if ((base - 1) * (base - 1) + (2 * base - 1) / 2 < diff) {
                result[i] = 2 * base - 1;
            }

            else {
                result[i] = 2 * base - 2;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    delete result;
}