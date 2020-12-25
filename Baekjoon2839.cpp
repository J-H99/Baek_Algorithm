#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int N;
    cin >> N;

    int solution = -1;
    int num_5kg = N / 5;

    while(1) {
        if (num_5kg == -1) {
            solution = -1;
            break;
        }

        else if ((N - num_5kg * 5) % 3 == 0) {
            solution = num_5kg + (N- num_5kg *5) / 3;
            break;
        }

        else {
            num_5kg--;
        }
    }

    cout << solution;
    return 0;
}  