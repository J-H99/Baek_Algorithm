#include <iostream>

using namespace std;
using LL = long long;

int main() {
    int N, B, C;
    LL sum = 0;
    cin >> N;

    LL* taker = new LL[N];
    LL* count = new LL[N];
    for (int i = 0; i < N; i++) {
        cin >> taker[i];
    }

    cin >> B >> C;

    for (int i = 0; i < N; i++) {
        if (taker[i] - B <= 0) {
            count[i] = 1;
        }

        else {
            count[i] = 1 + ((taker[i] - B) - 1) / C + 1;
        }
    }

    for (int i = 0; i < N; i++) {
        sum += count[i];
    }

    cout << sum;
    delete taker;
    delete count;
    return 0;
}