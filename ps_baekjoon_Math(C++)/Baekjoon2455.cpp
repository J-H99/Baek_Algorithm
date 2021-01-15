#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int arr[4] = {0,};
    pair<int, int> person[4];

    person[0].first = person[0].second = 0;
    
    for (int i = 0; i < 4; i++) {
        cin >> person[i].first >> person[i].second;
        
        if (i == 0) {
            arr[i] = person[i].second - person[i].first;
        }

        else {
            arr[i] += arr[i - 1] + person[i].second - person[i].first;
        }
    }

    cout << *max_element(arr, arr + 4);
    return 0;
}