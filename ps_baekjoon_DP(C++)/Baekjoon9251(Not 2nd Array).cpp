#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main() {
    int before = 0;
    string first, second;
    cin >> first >> second;
    
    first = "0" + first;
    second = "0" + second;

    int* sequence = new int[second.length()];
    memset(sequence, 0, sizeof(int) * second.length());

    for(int i = 1; i < first.length(); i++) {
        before = 0;
        for(int j = 1; j < second.length(); j++) {
            if (sequence[j] > before) { 
                before = sequence[j];
            }
            
            else if (first[i] == second[j]) {
                sequence[j] = before + 1;
            }
        }
    }

    cout << *max_element(sequence, sequence + second.length());
    delete sequence;
    return 0;
}