#include <iostream>
#include <cstring>

using namespace std;

int main() {
    int val[10];
    int ret[42];
    int cnt = 0;

    memset(ret, 0, sizeof(ret));
    for (int i = 0; i < 10; i++) {
        cin >> val[i];
        
        ret[val[i] % 42]++;
    }

    for (int i = 0; i < 42; i++) {
        if (ret[i] != 0) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}