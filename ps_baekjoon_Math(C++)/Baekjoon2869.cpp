#include <iostream>
#include <cmath>

using namespace std;
using LL = long long;

int main() {
    LL A, B, V;
    cin >> A >> B >> V;

    cout << (V - B - 1) / (A - B) + 1;
    return 0;
}