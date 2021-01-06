#include <iostream>

using namespace std;

int reverse(int x) {
    int ans;
    
    ans = (x % 10) * 100;
    ans += ((x / 10) % 10) * 10;
    ans += ((x / 10) / 10);

    return ans;
}

int main() {
    int A, B;
    cin >> A >> B;

    if (A % 10 < B % 10) {
        cout << reverse(B);
    }

    else if (A % 10 > B % 10) {
        cout << reverse(A);
    }

    else {
        if ((A / 10) % 10 < (B / 10) % 10) {
            cout << reverse(B);
        }

        else if ((A / 10) % 10 > (B / 10) % 10) {
            cout << reverse(A);
        }

        else {
            if ((A / 10) / 10 < (B / 10) / 10) {
                cout << reverse(B);
            }

            else {
                cout << reverse(A);
            }
        }
    }
    return 0;
}