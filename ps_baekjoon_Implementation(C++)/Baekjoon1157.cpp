#include <iostream>
#include <algorithm>
#include <cstring>
#include <string>

using namespace std;

int main() {
    int max_value, cnt = 0, maxidx;
    string word;

    cin >> word;
    int alphabet[26];

    memset(alphabet, 0, sizeof(int) * 26);
    for (int i = 0; i < word.length(); i++) {
        word[i] = toupper(word[i]);
        alphabet[word[i] - 'A']++;
    }

    max_value = *max_element(alphabet, alphabet + 26);

    for (int i = 0; i < 26; i++) {
        if (alphabet[i] == max_value) {
            maxidx = i;
            cnt++;
        }
    }

    if (cnt >= 2) {
        cout << '?';
    } 

    else if (cnt == 1) {
        cout << (char)(maxidx + 'A');
    }
    return 0;
}