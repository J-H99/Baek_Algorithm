#include <iostream>

using namespace std;

int main() {
    int sum = 0, score;

    for (int i = 0; i < 5; i++){
        cin >> score;
        if (score < 40) {
            score = 40;
        }
        sum += score;
    }

    cout << sum / 5;
}