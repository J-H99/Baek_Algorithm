#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;
using LL = long long;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    int T;
    cin >> T;

    int* input = new int[T];
    int* temp = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> input[i];
        temp[i] = input[i];
    }

    sort(input, input + T, compare);
    LL* DP = new LL[input[T - 1] + 1];
    
    for (int i = 0; i <= input[T - 1]; i++) {
        if (i == 0) {
            DP[i] = 1; 
        }    
        
        else if (i == 1) {
            DP[i] = 1;
        }

        else if (i == 2) {
            DP[i] = 2;
        }

        else if (i == 3) {
            DP[i] = 4;
        }

        else {
            DP[i] = DP[i - 1] + DP[i - 2] + DP[i - 3] + DP[i - 4];
        }
    }

    for (int i = 0; i < T; i++) {
        cout << DP[temp[i]] << endl;
    }

    delete input;
    delete temp;
    delete DP;
    return 0;
}