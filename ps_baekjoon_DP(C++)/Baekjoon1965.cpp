#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int n;
    cin >> n;

    int* box_size = new int[n];
    int* DP = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> box_size[i];
        DP[i] = 1;
    }

    DP[0] = 1;
    for (int i = 1; i < n; i++) {
        for (int j = i - 1; j >= 0; j--) {
            if (box_size[i] > box_size[j]) {
                DP[i] = max(DP[i], DP[j] + 1);
            }
        }
    }

    cout << *max_element(DP, DP + n);

    delete box_size;
    delete DP;
    return 0;
}