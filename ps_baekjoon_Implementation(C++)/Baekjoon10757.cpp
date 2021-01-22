#include <iostream>
#include <string>

using namespace std;

int main() {
    string num1, num2, temp, ans = "";
    cin >> num1 >> num2;

    int carry = 0, ret = 0, i, j;
    if (num1.length() < num2.length()) {
        temp = num1;
        num1 = num2;
        num2 = temp;
    }

    for (i = num1.length() - 1, j = num2.length() - 1; i >= 0 && j >= 0; i--, j--) {
        ret = (carry + (num1[i] - '0') + (num2[j] - '0')) % 10;
        carry = (carry + (num1[i] - '0') + (num2[j] - '0')) / 10;
        ans += ret + '0';

        if (i == 0 && carry == 1) {
            ans += '1';
        }
    }

    for (; i >= 0; i--) {
        ret = (carry + (num1[i] - '0')) % 10;
        carry = (carry + (num1[i] - '0')) / 10;
        ans += ret + '0';

        if (i == 0 && carry == 1) {
            ans += '1';
        }  
    }

    for (int i = ans.length() - 1; i >= 0; i--) {
        cout << ans[i];
    }

    return 0;
}