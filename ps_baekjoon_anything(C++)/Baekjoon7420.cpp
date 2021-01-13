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
    int N, L, next = 2, idx = 0, dest_point, starting_point, hull_number, temp_x, temp_y;
    cin >> N >> L;

    double dist, barrier = 0;
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

    hull_number = convex_hull.size();
    pair<int, int>* point_vector = new pair<int, int>[hull_number];
    double* vector_size = new double[hull_number];
    double* angle = new double[hull_number];

    temp_x = point_arr[0].x;

    temp_y = point_arr[0].y;
    for (int i = 0; i < hull_number; i++) {

        
        point_vector[i].first = point_arr[convex_hull.top()].x - temp_x;
        point_vector[i].second = point_arr[convex_hull.top()].y - temp_y;
        
        temp_x = point_arr[convex_hull.top()].x;
        temp_y = point_arr[convex_hull.top()].y;
        convex_hull.pop();
    }

    // 1. point_vector의 크기들은 기본적으로 다 더해야함
    for (int i = 0; i < hull_number; i++) {
        vector_size[i] = sqrt(point_vector[i].first * point_vector[i].first + point_vector[i].second * point_vector[i].second);
        barrier += vector_size[i];
    }

    // 2. 둥근 모서리 각 구해서 더해야함
    // 모서리 = 각 * L = acos(내적) * L
    // 먼저 내적들을 구하고 -> 저장
    // i번째 angle : point_vector[i]와 point_vector[i + 1]이 이루는 각의 cos 저장
    for (int i = 0; i < hull_number - 1; i++) {
        angle[i] = (point_vector[i].first * point_vector[i + 1].first + point_vector[i].second * point_vector[i + 1].second) / (vector_size[i] * vector_size[i + 1]);
    }

    // hull_number - 1 하면 10 벡터와 21벡터 이루는 각 저장 안됨 
    angle[hull_number - 1] = (point_vector[hull_number - 1].first * point_vector[0].first + point_vector[hull_number - 1].second * point_vector[0].second) / (vector_size[hull_number - 1] * vector_size[0]);
    
    for (int i = 0; i < hull_number; i++) {
        cout << acos(angle[i]) << endl;
    }

    // 이제 cos에 대한 acos 구해서 L이랑 곱하기
    for (int i = 0; i < hull_number; i++) {
        barrier += acos(angle[i]) * L;
    }
    
    cout << round(barrier);
    delete point_arr;
    delete point_vector;
    delete vector_size;
    delete angle;
    return 0;
}