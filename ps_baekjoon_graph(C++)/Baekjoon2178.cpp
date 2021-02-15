#include <iostream>
#include <cstdio>
#include <queue>

using namespace std;

int dir_y[4] = {0, -1, 0, 1};
int dir_x[4] = {1, 0, -1, 0};

int main() {
    int N, M;
    bool check;
    queue<pair<int, int>> q;
    queue<pair<int, int>> path;
    scanf("%d %d", &N, &M);

    int** Maze = new int*[N];
    bool** visited = new bool*[N];
    int** dist = new int*[N];
    for (int i = 0; i < N; i++) {
        Maze[i] = new int[M];
        visited[i] = new bool[M];
        dist[i] = new int[M];
        for (int j = 0; j < M; j++) {
            scanf("%1d", &Maze[i][j]);
            visited[i][j] = false;
            if (Maze[i][j] == 1) {
                dist[i][j] = 0;
            }

            else {
                dist[i][j] = -1;
            }
        }
    }


    q.push({0, 0});
    dist[0][0] = 1;
    visited[0][0] = true;
    while(!q.empty()) {
        check = false;
        auto curr = q.front();
        q.pop();

        if (curr.first == N - 1 && curr.second == M - 1) {
            break;
        }

        else {
            for (int i = 0; i < 4; i++) {
                int next_y = curr.first + dir_y[i];
                int next_x = curr.second + dir_x[i];

                if (next_x < 0 || next_y < 0 || next_x >= M || next_y >= N) {
                    continue;
                }

                else if (Maze[next_y][next_x] == 1) {
                    if (dist[next_y][next_x] >= 0 && !visited[next_y][next_x]) {
                        visited[next_y][next_x] = true;
                        q.push({next_y, next_x});
                        dist[next_y][next_x] = dist[curr.first][curr.second] + 1;
                    }
                }
            }
        }
    }

    printf("%d", dist[N - 1][M - 1]);
    for (int i = 0; i < N; i++) {
        delete Maze[i];
        delete dist[i];
        delete visited[i];
    }
    delete Maze;
    delete dist;
    delete visited;
    return 0;
}