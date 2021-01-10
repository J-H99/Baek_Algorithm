#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n, cnt;
    vector<int> result;

    while(true) {
        cin >> n;
        if (n == 0) {
            break;
        }

        else {
            cnt = 0;
            int *prime_arr = new int[2 * n + 1];

            for (int i = 2; i <= 2 * n; i++) {
                prime_arr[i] = i;
            }

            for (int i = 2; i <= 2 * n; i++) {
                if (prime_arr[i] == 0) {
                    continue;
                }

                for (int j = i * 2; j <= 2 * n; j += i) {
                    prime_arr[j] = 0;
                }
            }

            for (int i = n + 1; i <= 2 * n; i++) {
                if (prime_arr[i] != 0) {
                    cnt++;
                }
            }
            result.push_back(cnt);
            delete prime_arr;
        }
    }

    for (auto i = result.begin(); i < result.end(); i++) {
        cout << *i << endl;
    }
    return 0;
}