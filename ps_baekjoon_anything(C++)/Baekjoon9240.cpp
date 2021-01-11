#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
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
    int N, next = 2, dest_point, starting_point, xPoint_Diff, yPoint_Diff, hull_number;
    cin >> N;

    double dist;
    Point* point_arr = new Point[N];
    double* score = new double[N];

    memset(score, 0, sizeof(double) * N);
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

    hull_number = convex_hull.size();
    pair<int, int>* convex_hull_point = new pair<int, int>[hull_number];

    for (int i = 0; i < hull_number; i++) {
        convex_hull_point[i].first = point_arr[convex_hull.top()].x;
        convex_hull_point[i].second = point_arr[convex_hull.top()].y;
        convex_hull.pop();
        score[i] = 0;
    }
    
    for (int i = 0; i < hull_number - 1; i++) {
        for (int j = i; j < hull_number - 1;j ++) {
            dist = sqrt((convex_hull_point[i].first - convex_hull_point[j + 1].first) * (convex_hull_point[i].first - convex_hull_point[j + 1].first) + (convex_hull_point[i].second - convex_hull_point[j + 1].second) * (convex_hull_point[i].second - convex_hull_point[j + 1].second));
            score[i] = max(dist, score[i]);
        }
    }
    
    cout << fixed;
    cout.precision(6);
    cout << *max_element(score, score + N);
    delete point_arr;
    delete convex_hull_point;
    delete score;
    return 0;
}