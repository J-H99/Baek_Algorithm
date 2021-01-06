#include <iostream>
#include <string>
#include <cstring>

using namespace std;

int main() {
    int T;
    string scoreboard;
    cin >> T;

    int* result = new int[T];
    memset(result, 0, sizeof(int)* T);
    for (int i = 0; i < T; i++) {
        cin >> scoreboard;

        scoreboard = 'X' + scoreboard;
        int* score = new int[scoreboard.length()];
        for (int k = 0; k < scoreboard.length(); k++) {
            score[k] = 1;
        }

        for (int j = 0; j < scoreboard.length(); j++) {
            if (scoreboard[j] == 'X') {
                score[j] = 0;
            }

            else if (scoreboard[j] == 'O' && scoreboard[j-1] == 'O') {
                score[j] = score[j-1] + 1;
            }
        }

        for (int j = 0; j < scoreboard.length(); j++) {
            result[i] += score[j];
        }

        delete score;   
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }
    delete result;
    return 0;
}