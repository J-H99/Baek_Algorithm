#include <iostream>
#include <cmath>

using namespace std;
using LL = long long;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int cnt = 0;
    bool check = true;
    LL K, ans, val = 3;
    cin >> K;

    if (K == 1 || K == 2 || K == 3) {
        cout << K;
    }

    else {
        cnt = 3;
        while (K != cnt) {
            val++;
            for (int i = floor(sqrt(val)); i >= 2; i--) {
                check = true;
                if (val % (i * i) == 0) {
                    check = false;
                    break;
                }
            }

            if (check) {
                cnt++;
            }
        }

        cout << val;
    }

    return 0;
}