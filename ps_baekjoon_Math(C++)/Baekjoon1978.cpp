#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, cnt = 0;
    bool check = true;
    cin >> N;

    int* value = new int[N];
    for (int i = 0; i < N; i++) {
        cin >> value[i];
    }

    for (int i = 0; i < N; i++) {
        check = true;

        if (value[i] == 1) {
            continue;
        }

        else if (value[i] == 2) {
            cnt++;
            continue;
        }
        
        else {
            for (int j = 2; j < value[i]; j++) {
                if (value[i] % j == 0) {
                    check = false;
                }
            }
        }

        if (check) {
           cnt++; 
        }
    }
    cout << cnt;
    return 0;  
}