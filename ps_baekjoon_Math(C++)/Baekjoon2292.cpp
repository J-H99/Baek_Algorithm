#include <iostream>

using namespace std;

int main() {
    long long N;
    long long sum = 1;
    int shell_num = 1;
    cin >> N;

    for(int i = 1; i <= N; i++) {
        if (i == sum + 1) {
            sum += shell_num * 6;
            shell_num++;
        }
    }

    cout << shell_num;
    return 0;
}