#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

int main() {
    vector<string> value;
    while(true) {
        int* arr = new int[3];
        cin >> arr[0] >> arr[1] >> arr[2];

        sort(arr, arr + 3);
        if (arr[0] == 0 && arr[1] == 0 && arr[2] == 0) {
            delete arr;
            break;
        }

        if (arr[2] * arr[2] == arr[0] * arr[0] + arr[1] * arr[1]) {
            value.push_back("right");
        }

        else {
            value.push_back("wrong");
        }

        delete arr;
    }

    for (auto i = value.begin(); i != value.end(); i++) {
        cout << *i << endl;
    }

    return 0;
}