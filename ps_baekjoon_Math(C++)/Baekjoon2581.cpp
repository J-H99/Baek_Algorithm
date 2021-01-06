#include <iostream>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int M, N, sum = 0, minimum;
    bool check = true;
    cin >> M >> N;

    int* prime_arr = new int[N + 1];
    for(int i = 2; i <= N; i++) {
        prime_arr[i] = i;
    }
    
    for (int i = 2; i <= N; i++) {
        if (prime_arr[i] == 0) {
            continue;
        }

        for (int j = i * 2; j <= N; j += i) {
            prime_arr[j] = 0;
        }
    }

    for (int i = M; i <= N; i++) {
        if (prime_arr[i] != 0 && check) {
            minimum = prime_arr[i];
            check = false;
        }
        sum += prime_arr[i];
    }

    if (check) {
        cout << -1;
    }

    else {
        cout << sum << "\n" << minimum;
    }  
    delete prime_arr;
    return 0;
}