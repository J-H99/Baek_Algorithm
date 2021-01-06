#include <iostream>

using namespace std;

int num_people[15][15];
int main() {
    int T, k, n;
    cin >> T;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> k >> n;

        for (int i = 0; i < 15; i++) {
            for (int j = 0; j < 15; j++) {
                num_people[i][j] = 0;
            }
        }

        for (int i = 0; i < n; i++) {
            num_people[0][i] = i + 1; 
        }

        for (int i = 1; i <= k; i++) { 
            for (int j = 0; j < n; j++) { 
                for (int m = j; m >= 0; m--) {
                    num_people[i][j] += num_people[i - 1][m];
                }
            }
        }
        result[i] = num_people[k][n - 1];
    }
    
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    delete result;
    return 0;
}