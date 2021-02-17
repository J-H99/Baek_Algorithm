#include <iostream>
#include <string>

using namespace std;

int main () {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    string sentence;
    int i = 0;

    while(i != 100) {
        getline(cin, sentence);
        i++;
        cout << sentence << "\n";
    }
    return 0;
}