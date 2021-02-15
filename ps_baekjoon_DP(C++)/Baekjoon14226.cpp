#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

struct Display {
    int emoticon, clipboard, time;
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int S, emoticon, clipboard, time;
    cin >> S;
    
    bool** DP = new bool*[S + 1];
    for (int i = 0; i <= S; i++) {
        DP[i] = new bool[S + 1];
        for (int j = 0; j <= S; j++) {
            DP[i][j] = false;
        }
    }


    DP[1][0] = true;
    queue<Display> q;
    q.push({ 1, 0, 0 });

    while(!q.empty()) {
        emoticon = q.front().emoticon;
        clipboard = q.front().clipboard;
        time = q.front().time;
        q.pop();

        if (emoticon == S) {
            break;
        }
        
        if (emoticon > 0 && emoticon <= S) {
            if (!DP[emoticon][emoticon]) {
                DP[emoticon][emoticon] = true;
                q.push({ emoticon, emoticon, time + 1});
            }

            if (clipboard > 0 && emoticon + clipboard <= S) {
                if (!DP[emoticon + clipboard][clipboard]) {
                    DP[emoticon + clipboard][clipboard] = true;
                    q.push({ emoticon + clipboard, clipboard, time + 1});
                }
            }

            if (!DP[emoticon - 1][clipboard]) {
                DP[emoticon - 1][clipboard] = true;
                q.push({ emoticon - 1, clipboard, time + 1});
            }
        }
    }

    cout << time << "\n";
    for (int i = 0; i <= S; i++) {
        delete DP[i];
    }
    delete DP;
    return 0;
}