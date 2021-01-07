#include <iostream>
#include <string>

using namespace std;

int main() {
    int cnt = 1;
    bool check = true;
    string sentence;
    getline(cin, sentence);

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] == ' ' && sentence[i-1] == ' ') {
            continue;
        }

        else if (sentence[i] == ' ') {
            if (i == 0 || i == sentence.length() - 1) {
                continue;
            }

            else {
                cnt++;
            }   
        }
    }

    for (int i = 0; i < sentence.length(); i++) {
        if (sentence[i] != ' ') {
            check = false;
        }
    }

    if (check) {
        cout << 0;
    }

    else {
        cout << cnt;
    }
    return 0;
}