#include <iostream>

using namespace std;

int main() {
    int N, X, value;
    cin >> N >> X;

    for (int i = 0; i < N; i++) {
        cin >> value;
        if (value < X) {
            cout << value << " ";
        }
    }
    return 0;
}