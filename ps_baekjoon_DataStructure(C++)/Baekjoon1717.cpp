#include <iostream>

using namespace std;

int find_set(int *parent, int x) {
    if (parent[x] == x) {
        return x;
    }

    return parent[x] = find_set(parent, parent[x]);
}

void union_set(int *parent, int x, int y) {
    x = find_set(parent, x);
    y = find_set(parent, y);

    if (x != y) {
        parent[y] = x;
    }
}

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int op, n, m, a, b;
    cin >> n >> m;

    int* parent = new int[n + 1];

    for (int i = 0; i <= n; i++) {
        parent[i] = i;
    }

    for (int i = 1; i <= m; i++) {
        cin >> op >> a >> b;

        if (op == 0) {
            union_set(parent, a, b);
        }

        else if (op == 1) {
            if (find_set(parent, a) == find_set(parent, b)) {
                cout << "YES\n";
            }

            else {
                cout << "NO\n";
            }
        }
    }

    delete parent;
    return 0;
}