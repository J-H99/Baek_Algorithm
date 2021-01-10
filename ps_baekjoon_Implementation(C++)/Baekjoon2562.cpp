#include <iostream>

using namespace std;

int main() {
    int cnt = 0, val, maximum = -1;

    for (int i = 0; i < 9; i++) {
        cin >> val;

        if (val > maximum) {
            maximum = val;
            cnt = i + 1;
        }
    }

    cout << maximum << endl;
    cout << cnt;
    return 0;
}