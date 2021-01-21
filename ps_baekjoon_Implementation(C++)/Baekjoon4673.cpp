#include <iostream>

using namespace std;

int main() {
    int j;
    int sum;
    bool check[10001];

    for (int i = 0; i <= 10000; i++) {
        check[i] = true;
    }

    for (int i = 1; i <= 10000; i++) {
        j = i;
        sum = i;

        while (j > 0) {
            sum += (j % 10);
            j /= 10;
        }

        if (sum <= 10000 && check[sum]) {
            check[sum] = false;
        }
    }

    for (int i = 1; i <= 10000; i++) {
        if (check[i]) {
            cout << i << endl;
        }
    }

    return 0;
}