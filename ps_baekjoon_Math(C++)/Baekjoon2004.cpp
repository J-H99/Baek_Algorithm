#include <iostream>
#include <algorithm>

using namespace std;
using LL = long long;

pair<LL, LL> ZeroReturn(LL n) {
    LL check2 = 0, check5 = 0;
    for (LL i = 2; i <= n; i *= 2) {
        check2 += n / i;
    }

    for (LL i = 5; i <= n; i *= 5) {
        check5 += n / i;
    }

    return {check2, check5};
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    LL n, m;
    pair<LL, LL> temp1, temp2, temp3;
    cin >> n >> m;

    temp1 = ZeroReturn(n);
    temp2 = ZeroReturn(n - m);
    temp3 = ZeroReturn(m);

    cout << min(temp1.first - temp2.first - temp3.first, temp1.second - temp2.second - temp3.second);
    return 0;
}