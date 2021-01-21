#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnt = 0;
    bool check = true;
    string word;
    cin >> word;

    for (int i = 0; i < word.length() - 1; i++) {
        check = true;
        if ((word[i] == 'l' && word[i + 1] == 'j') || (word[i] == 'c' && word[i + 1] == '=') || (word[i] == 'c' && word[i + 1] == '-') || (word[i] == 'd' && word[i + 1] == '-') || (word[i] == 'l' && word[i + 1] == 'j') || (word[i] == 'n' && word[i + 1] == 'j') || (word[i] == 's' && word[i + 1] == '=') || (word[i] == 'z' && word[i + 1] == '=')) {
            cnt++;
            i++;
            check = false;
        }
        
        else if (i < word.length() - 2 && word[i] == 'd' && word[i + 1] == 'z' && word[i + 2] == '=') {
            cnt++;
            i += 2;
            check = false;
        }

        if (check) {
            cnt++;
        }
    }

    cout << cnt;
    return 0;
}