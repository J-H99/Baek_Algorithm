#include <iostream>
#include <cmath>

using namespace std;

int main() {
    int T, H, W, N;
    cin >> T;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> H >> W >> N;

        if (N % H == 0) {
            result[i] = 100 * H + N / H;
        }
        else {
            result[i] = 100 * (N % H) + ceil(N / (double)H);
        }
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    delete result;
    return 0;
}