#include <iostream>

using namespace std;

int main() {
    int num1, num2;
    long long ans = 0;

    cin >> num1 >> num2;
    for(int i = 1; num2 > 0; i *= 10, num2 /= 10) {
        cout << num1 * (num2 % 10) << endl;
        ans += i * (num1 * (num2 % 10));
    }
    cout << ans;
    return 0;
}