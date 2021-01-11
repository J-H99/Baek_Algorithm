#include <iostream>
#include <cstring>
#include <string>
#include <algorithm>
#include <stack>
#include <typeinfo>

using namespace std;

int main() {
    int first_temp, second_temp;
    string first, second, temp;
    stack<int> lcs_string;
    cin >> first >> second;

    first = "0" + first;
    second = "0" + second;
    first_temp = first.length() - 1;
    second_temp = second.length() - 1;
    
    int** dp_sequence = new int*[second.length()];
    for(int i = 0; i < second.length(); i++) {
        dp_sequence[i] = new int[first.length()];
        memset(dp_sequence[i], 0, sizeof(int)* first.length());
    }
    
    for (int i = 1; i < second.length(); i++) {
        for (int j = 1; j < first.length(); j++) {
            if (second[i] == first[j]) {
                dp_sequence[i][j] = dp_sequence[i - 1][j - 1] + 1;
            }

            else {
                dp_sequence[i][j] = max(dp_sequence[i - 1][j], dp_sequence[i][j - 1]);
            }
        }
    }

    cout << dp_sequence[second.length() - 1][first.length() - 1] << endl;

    while (dp_sequence[second_temp][first_temp] != 0) {
        if (dp_sequence[second_temp][first_temp] == dp_sequence[second_temp][first_temp - 1]) {
            first_temp--;
        }

        else if (dp_sequence[second_temp][first_temp] == dp_sequence[second_temp - 1][first_temp]) {
            second_temp--;
        }

        else if (dp_sequence[second_temp][first_temp] - 1 == dp_sequence[second_temp - 1][first_temp - 1]) {
            lcs_string.push(second_temp);
            first_temp--;
            second_temp--;
        }
    }
    
    while(!lcs_string.empty()) {
        cout << second[lcs_string.top()];
        lcs_string.pop();
    }

    for (int i = 0; i < second.length(); i++) {
        delete dp_sequence[i];
    }
    delete dp_sequence;
    return 0;
}