#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int E, S, M, temp_E = 1, temp_S = 1, temp_M = 1, year = 1;
    cin >> E >> S >> M;

    while(temp_E != E || temp_S != S || temp_M != M) {
        temp_E++;
        temp_S++;
        temp_M++;
        year++;
        
        if (temp_E == 16) {
            temp_E = 1;
        }

        if (temp_S == 29) {
            temp_S = 1;
        }

        if (temp_M == 20) {
            temp_M = 1;
        }
    }

    cout << year;
    return 0;
}