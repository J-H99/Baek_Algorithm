#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T;
    cin >> T;

    int* input = new int[T];
    int* temp = new int[T];
    pair<int, int>* result = new pair<int, int>[T];
    for (int i = 0; i < T; i++) {
        cin >> input[i];
        temp[i] = input[i];
    }

    sort(temp, temp + T);

    int* prime_arr = new int[temp[T - 1]];
    memset(prime_arr, 0, sizeof(int) * temp[T - 1]);

    for (int i = 2; i < temp[T - 1]; i++) {
        prime_arr[i] = i;

    }

    for (int i = 2; i < temp[T - 1]; i++) {
        if (prime_arr[i] == 0) {
            continue;
        }
            
        for (int j = i * 2; j < temp[T - 1]; j += i) {
            prime_arr[j] = 0;
        }
    }

    for (int i = 0; i < T; i++) {
        for (int j = 2; j < input[i]; j++) {
            if (prime_arr[j] != 0 && prime_arr[input[i] - j] != 0 && 2 * j <= input[i]) {
                result[i].first = j;
                result[i].second = input[i] - j;
            }
        }
    }

    for (int i = 0; i < T; i++) {
        cout << result[i].first << " " << result[i].second << "\n";
    }

    delete prime_arr;
    delete temp;
    delete result;
    delete input;
    return 0;
}