#include <iostream>

using namespace std;

int main() {
    int N, fact = 1;
    cin >> N;

    for (int i = 0; i < N; i++){
        fact *= (i + 1);
    }

    cout << fact;
}