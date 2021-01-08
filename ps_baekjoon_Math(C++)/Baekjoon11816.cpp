#include <iostream>
#include <string>

using namespace std;

int main() {
    string X;
    cin >> X;
    int sum, pow;

    if (X.length() == 1) {
        cout << X;
    }

    else if (X[0] == '0' && X[1] != 'x') {
        // octal
        sum = 0;
        pow = 1;
        for (int i = X.length() - 1; i >= 1; i--) {
            sum += (X[i] - '0') * pow;
            pow *= 8;
        }

        cout << sum;
    }

    else if (X[0] == '0' && X[1] == 'x') {
        // hexa
        sum = 0;
        pow = 1;
        for (int i = X.length() - 1; i >= 2; i--) {
            if (X[i] - '0' <= 9 && X[i] - '0' >= 0) {
                sum += (X[i]- '0') * pow;
            }

            else {
                sum += (X[i] - 87) * pow;
            }
            pow *= 16;
        }
        cout << sum;
    }

    else {
        cout << X;
    }

    return 0;
}