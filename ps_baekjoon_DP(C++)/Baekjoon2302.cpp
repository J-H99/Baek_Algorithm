#include <iostream>

using namespace std;
using LL = long long;

int main() {
    int N, M;
    LL sum = 1;
    cin >> N >> M;

    if (N == 1 || N == 2) {
        cout << 1;
    }

    else {
        int* num = new int[N];
        int *DP = new int[N + 1];

        num[0] = N + 1;
        for (int i = 0; i < M; i++) {
            cin >> num[i];
        }
        
        DP[0] = 1;
        DP[1] = 1;
        DP[2] = 2;
        for (int i = 3; i <= N; i++) {
            DP[i] = DP[i - 1] + DP[i - 2];
        }

        for (int i = 0; i <= M; i++) {
            if (i == 0) {
                sum *= DP[num[i] - 1];
            }
            
            else if (i == M) {
                sum *= DP[N - num[i - 1]];
            }

            else {
                sum*= DP[num[i] - num[i - 1] - 1];
            }
        }

        cout << sum;
        delete DP;
        delete num;
    }
    return 0;
}