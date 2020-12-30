#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;

    int res[10];
    memset(res, 0, sizeof(res));
    long long ans = A * B * C;
    for (; ans > 0; ans /= 10) {
        res[ans % 10]++;
    }

    for (int i = 0; i < 10; i++) {
        cout << res[i] << endl;
    }
}