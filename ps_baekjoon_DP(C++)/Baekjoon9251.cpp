#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    int max_value = 0, max_cand;
    string first, second;
    cin >> first >> second;

    first = "0" + first;
    second = "0" + second;

    int** dp_sequence = new int*[second.length()];
    for(int i = 0; i < second.length(); i++) {
        dp_sequence[i] = new int[first.length()];
        memset(dp_sequence[i], 0, sizeof(int)* first.length());
    }
    
    for (int i = 1; i < second.length(); i++) {
        for (int j = 1; j < first.length(); j++) {
            if (second[i] == first[j]) {
                dp_sequence[i][j] = dp_sequence[i-1][j-1] + 1;
            }

            else {
                dp_sequence[i][j] = max(dp_sequence[i-1][j], dp_sequence[i][j-1]);
            }
        }
    }

    cout << *max_element(dp_sequence[second.length() - 1], dp_sequence[second.length() - 1] + first.length());
    for (int i = 0; i < second.length(); i++) {
        delete dp_sequence[i];
    }
    delete dp_sequence;
    return 0;
}