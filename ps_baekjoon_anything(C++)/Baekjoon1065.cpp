#include <iostream>
#include <string>

using namespace std;

int main() {
    int N, cnt = 0, diff;
    bool check;
    string int_string;
    cin >> N;

    for (int i = 1; i <= N; i++) {
        int_string = to_string(i);
        check = true;

        if (int_string.length() == 1 || int_string.length() == 2) {
            cnt++;
        }

        else {
            diff = int_string[0] - int_string[1];
            for (int j = 1; j < int_string.length() - 1; j++) {
                if (int_string[j] - int_string[j + 1] != diff) {
                    check = false;
                }
            }

            if (check) {
                cnt++;
            }
        }
    }

    cout << cnt;
    return 0;
}