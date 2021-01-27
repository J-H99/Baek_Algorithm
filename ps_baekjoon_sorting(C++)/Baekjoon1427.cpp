#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    char temp;
    cin >> number;

    for (int i = 0; i < number.length(); i++) {
        for (int j = 0; j < number.length() - i - 1; j++) {
            if (number[j] < number[j + 1]) {
                temp = number[j + 1];
                number[j + 1] = number[j];
                number[j] = temp;
            }
        }
    }

    cout << number;
    return 0;
}