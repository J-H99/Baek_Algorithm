#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    bool check = true;
    int n, m;
    int result = 1;

    scanf("%d %d", &n, &m);
    
    int** inp = new int*[n];
    int** DP = new int*[n];

    for (int i = 0; i < n; i++) {
        inp[i] = new int[m];
        DP[i] = new int[m];

        for (int j = 0; j < m; j++) {
            scanf("%1d", &inp[i][j]);
            DP[i][j] = inp[i][j];

            if (DP[i][j] == 1) {
                check = false;
            }
        }
    }

    if (check) {
        printf("%d", 0);
    }

    else {
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (inp[i][j] == 1) {
                    DP[i][j] = min(DP[i - 1][j], min(DP[i][j - 1], DP[i - 1][j - 1])) + 1;
                    result = max(DP[i][j], result);
                }
            }
        }

        printf("%d", result * result);
    }

    for (int i = 0; i < n; i++) {
        delete inp[i];
        delete DP[i];
    }
    delete inp;
    delete DP;
    return 0;
}