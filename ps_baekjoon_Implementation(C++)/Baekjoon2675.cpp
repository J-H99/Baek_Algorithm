#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T, R;
    string sentence;
    cin >> T;

    vector<string> result;
    for (int i = 0; i < T; i++) {
        cin >> R >> sentence;

        string store = "";

        for (int j = 0; j < sentence.length(); j++) {
            for (int k = 0; k < R; k++) {
                store = store + sentence[j];
            }
        }
        result.push_back(store);
    }

    for (auto i = result.begin(); i < result.end(); i++) {
        cout << *i << "\n";
    }

    return 0;
}