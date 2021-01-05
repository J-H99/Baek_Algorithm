#include <iostream>
#include <cmath>

using namespace std;
using LL = long long;

int main() {
    LL A, B, C;
    cin >> A >> B >> C;

    if (C - B <= 0) {
        cout << -1;
    }

    else {
        cout << (A / (C - B)) + 1;
    }
    return 0;
}