#include <iostream>
#include <string>

using namespace std;

bool check(char a, string word) {
    for (int i = 0; i < word.length(); i++) {
        if (word[i] == a) {
            return true;
        }
    }

    return false;
}

int main() {
    int sum = 0;
    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        if (check(word[i], "ABC")) {
            sum += 3;
        } 

        else if (check(word[i], "DEF")) {
            sum += 4;
        }
        
        else if (check(word[i], "GHI")) {
            sum += 5;
        }

        else if (check(word[i], "JKL")) {
            sum += 6;
        }

        else if (check(word[i], "MNO")) {
            sum += 7;
        }        

        else if (check(word[i], "PQRS")) {
            sum += 8;
        }

        else if (check(word[i], "TUV")) {
            sum += 9;
        }

        else if (check(word[i], "WXYZ")) {
            sum += 10;
        }
    }

    cout << sum;
    return 0;
}