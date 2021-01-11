#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;
using LL = long long;

struct Point {
    int x, y;
    int diff_x = 1, diff_y = 0;
};

bool Compare(const Point &A, const Point &B) {
    if (A.y != B.y) {
        return A.y < B.y;
    }

    else {
        return A.x < B.x;
    }
}

bool Compare_diff(const Point& A, const Point& B) {
    if (1LL * A.diff_y * B.diff_x != 1LL * A.diff_x * B.diff_y) {
        return 1LL * A.diff_y * B.diff_x < 1LL * A.diff_x * B.diff_y;
    }
    return Compare(A, B);
}

LL CCW(const Point& A, const Point& B, const Point& C) {
    return 1LL * (B.x - A.x) * (C.y - A.y) - 1LL * (B.y - A.y) * (C.x - A.x);
}

int main() {
    int N, next = 2, dest_point, starting_point;
    cin >> N;

    Point* point_arr = new Point[N];
    stack<int> convex_hull;
    for (int i = 0; i < N; i++) {
        cin >> point_arr[i].x >> point_arr[i].y;
    }

    sort(point_arr, point_arr + N, Compare);
    for (int i = 1; i < N; i++) {
        point_arr[i].diff_x = point_arr[i].x - point_arr[0].x;
        point_arr[i].diff_y = point_arr[i].y - point_arr[0].y;
    }

    sort(point_arr + 1, point_arr + N, Compare_diff);

    convex_hull.push(0);
    convex_hull.push(1);
    for(int i = next; i < N; i++) {
        while(convex_hull.size() >= 2) {
            dest_point = convex_hull.top();
            convex_hull.pop();

            starting_point = convex_hull.top();

            if (CCW(point_arr[starting_point], point_arr[dest_point], point_arr[i]) > 0) {
                convex_hull.push(dest_point);
                break;
            }
        }

        convex_hull.push(i);
    }

    cout << convex_hull.size();
    delete point_arr;
    return 0;
}