#include <iostream>
#include <string>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    
    int sum = 0, j = 1;
    string hex;
    cin >> hex;

    for (int i = hex.length() - 1; i >= 0; i--) {
        if (hex[i] <= '9' && hex[i] >= '0') {
            sum += j * (hex[i] - '0');
        }

        else {
            sum += j * (hex[i] - 'A' + 10);
        }

        j *= 16;
    }

    cout << sum;
    return 0;
}