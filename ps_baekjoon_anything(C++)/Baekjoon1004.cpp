#include <iostream>

using namespace std;

int main() {
    int T;
    cin >> T;
    int x1, y1, x2, y2, cx, cy, r, cnt, n;

    int* result = new int[T];
    for (int i = 0; i < T; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        cin >> n;
        cnt = 0;
        
        for (int i = 0; i < n; i++) {
            cin >> cx >> cy >> r;
            if ((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) < r * r && (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) > r * r) {
                cnt++;
            }

            else if ((cx - x1) * (cx - x1) + (cy - y1) * (cy - y1) > r * r && (cx - x2) * (cx - x2) + (cy - y2) * (cy - y2) < r * r) {
                cnt++;
            }
        }

        result[i] = cnt;
    }

    for (int i = 0; i < T; i++) {
        cout << result[i] << endl;
    }

    delete result;
    return 0;
}