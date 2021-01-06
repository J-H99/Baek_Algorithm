#include <iostream>

using namespace std;

int gcd(int x, int y) {
    if (y == 0) {
        return x;
    }

    else {
        if (x < y) {
            int temp = x;
            x = y;
            y = temp;
        }

        return gcd(y, x % y);
    }
}

int main() {
    int x, y;
    cin >> x >> y;
    
    int gcd_val = gcd(x, y);
    // GCD
    cout << gcd_val << endl;
    // LCM
    cout << x * y / gcd_val << endl;
    return 0;
}