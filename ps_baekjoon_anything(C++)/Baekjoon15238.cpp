#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main() {
    int size, max = -1;
    char maxidx;
    int alphabet[26] = {0, };
    string word;
    cin >> size >> word;

    for (int i = 0; i < size; i++) {
        alphabet[word[i] - 'a']++;

        if (max < alphabet[word[i] - 'a']) {
            maxidx = word[i];
            max = alphabet[word[i] - 'a'];
        }
    }

    cout << maxidx << " " << *max_element(alphabet, alphabet + 26);
    return 0;
}