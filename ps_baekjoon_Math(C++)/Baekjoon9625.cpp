#include <iostream>

using namespace std;

int main() {
    int K, numA = 1, numB = 0, temp;
    cin >> K;

    for (int i = 0; i < K; i++) {
        temp = numB;
        numB = numA + numB;
        numA = temp;
    }

    cout << numA << " " << numB;
    return 0;
}