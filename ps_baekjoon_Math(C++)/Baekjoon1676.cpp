#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N, divisor, check2 = 0, check5 = 0;
    cin >> N;

    for (int i = 2; i <= N; i++) {
        divisor = i;

        while (divisor >= 2) {
            if (divisor % 2 != 0 && divisor % 5 != 0) {
                break;
            }
            
            if (divisor % 2 == 0) {
                check2++;
                divisor /= 2;
            }

            if (divisor % 5 == 0) {
                check5++;
                divisor /= 5;
            }
        }
    }

    cout << min(check2, check5);
    return 0;
}