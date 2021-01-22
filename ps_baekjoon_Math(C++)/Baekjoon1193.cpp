#include <iostream>

using namespace std;

int main() {
    int X, i = 1, j = 1, cnt = 1;
    cin >> X;

    if (X == 1) {
        cout << "1/1";
        return 0;
    }

    for (int k = 2; k <= X; k++) {
        if (i == 1 && j == 1) {
            j++;
            cnt++;
            continue;
        }

        if (cnt % 2 == 0) {
            if (i == 1 & j != 1) {
                i++;
                j--;
            }

            else if (i != 1 && j == 1) {
                i++;
                cnt++;
            }

            else if (i != 1 && j != 1){
                i++;
                j--;
            }
        }

        else if (cnt % 2 == 1) {
            if (j == 1 && i != 1) {
                i--;
                j++;
            }

            else if (i == 1 && j != 1) {
                j++;
                cnt++;
            }

            else if (i != 1 && j != 1) {
                i--;
                j++;
            }
        }
    }

    cout << i << "/" << j;
    return 0;
}