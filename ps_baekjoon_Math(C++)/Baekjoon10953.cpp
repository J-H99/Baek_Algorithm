#include <iostream>
#include <string>

using namespace std;

int main() {
    int T, idx;
    cin >> T;
    string numbers;
    string first, second;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> numbers;
        for(int j = 0; j < numbers.length(); j++) {
            if (numbers[j] == ',') {
                idx = j;
                break;
            }
        }

        first = numbers.substr(0, idx);
        second = numbers.substr(idx + 1, numbers.length());
        result[i] = (atoi(first.c_str())) + (atoi(second.c_str()));
    }
    
    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    delete result;
    return 0;
}