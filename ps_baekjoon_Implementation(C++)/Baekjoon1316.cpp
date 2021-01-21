#include <iostream>
#include <string>

using namespace std;

bool checker(string word) {
    bool alphabet[26];

    for (int i = 0; i < 26; i++) {
        alphabet[i] = true;
    }

    for (int i = 0; i < word.length(); i++) {
        if (i == 0) {
            alphabet[word[i] - 'a'] = false;
            continue;
        }

        if (word[i] == word[i - 1]) {
            continue;
        }

        else if (word[i] != word[i - 1]) {
            if (!alphabet[word[i] - 'a']) {
                return false;
            }
            alphabet[word[i] - 'a'] = false;
        }
    }
    return true;
}

int main() {
    int N, cnt = 0;
    string word;
    cin >> N;

    for (int i = 0; i < N; i++) {
        cin >> word;
        if (checker(word)) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}