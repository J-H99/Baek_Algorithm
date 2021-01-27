#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int N, frequent_val, max_val, min_val, idx, check = 0;
    double average = 0;
    cin >> N;

    int* arr = new int[N];
    int count[8001] = {0, };
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
        average += arr[i] / (double)N;
        count[arr[i] + 4000]++;
    }

    sort(arr, arr + N, compare);
    frequent_val = *max_element(count, count + 8001);
    for (int i = 0; i <= 8000; i++) {
        if (count[i] == frequent_val) {
            idx = i;
            check++;
        }

        if (check == 2) {
            break;
        }
    }


    max_val = *max_element(arr, arr + N);
    min_val = *min_element(arr, arr + N);

    cout << round(average) << "\n";
    
    if (N % 2 == 0) {
        cout << arr[N / 2 - 1] << "\n";
    }

    else {
        cout << arr[N / 2] << "\n";
    }
    cout << idx - 4000 << "\n";
    cout << max_val - min_val;
    delete arr;
    return 0;
}