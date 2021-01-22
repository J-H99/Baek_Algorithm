#include <iostream>
#include <algorithm>

using namespace std;

bool compare(const pair<int, int>& x, const pair<int, int>& y) {
    if (x.first == y.first) {
        return y.first < y.second;
    }
    return x.first < y.first;
}

int main() {
    pair<int, int> point[3];
    cin >> point[0].first >> point[0].second >> point[1].first >> point[1].second >> point[2].first >> point[2].second;

    sort(point, point + 3, compare);

    if (point[0].first == point[1].first) {
        if (point[2].second == point[0].second) {
            cout << point[2].first << " " << point[1].second;
        }

        else {
            cout << point[2].first << " " << point[0].second;
        }
    }

    else {
        if (point[0].second == point[1].second) {
            cout << point[0].first << " " << point[2].second;
        }

        else {
            cout << point[0].first << " " << point[1].second;
        }
    }

    return 0;
}