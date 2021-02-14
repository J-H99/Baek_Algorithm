#include <iostream>
#include <string>

using namespace std;

int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string sentence;

    while(true) {
        getline(cin, sentence);
        if (sentence == "") {
            break;
        }
        cout << sentence << "\n";
    }
    return 0;
}