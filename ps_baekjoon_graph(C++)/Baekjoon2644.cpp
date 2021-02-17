#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

class Graph {
public:
    int N;
    vector<vector<int>> connect;

    Graph(): N(0) {}
    Graph(int n): N(n) {
        connect.resize(N);
    }

    void addEdge(int u, int v) {
        connect[u].push_back(v);
        connect[v].push_back(u);
    }

    void sortList() {
        for (int i = 0; i < N; i++) {
            sort(connect[i].begin(), connect[i].end());
        }
    }
};

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, x, y, m, a1, a2;
    cin >> n >> x >> y >> m;

    Graph G(n);
    vector<bool> visited(G.N, false);
    queue<int> q;
    for (int i = 0; i < m; i++) {
        cin >> a1 >> a2;
        G.addEdge(a1 - 1, a2 - 1);
    }

    q.push(x - 1);
    visited[x - 1] = true;

    int level = 0, qSize, curr;
    while (!q.empty()) {
        qSize = q.size();
        for (int i = 0; i < qSize; i++) {
            curr = q.front();
            q.pop();

            if (curr == y - 1) {
                cout << level;
                return 0;
            }
            for (int next : G.connect[curr]) {
                if (!visited[next]) {
                    visited[next] = true;
                    q.push(next);
                }
            }
        }
        level++;
    }

    cout << -1;
    return 0;
}