#include <iostream>

using namespace std;

int main() {
    double x, y, res_x, res_y;
    cin >> x >> y;

    cout << fixed;
    cout.precision(2);
    if (x == 0 && y == 0) {
        cout << "125.00 125.00";
    }

    else if (y == 0) {
        if (x == 125) {
            cout << "0.00 250.00";
        }

        else if (x < 125) {
            res_y = 31250 / (250 - x);
            res_x = 250 - res_y;
            cout << res_x << " " << res_y;
        }

        else {
            res_y = 31250 / x;
            cout << "0.00" << " " << res_y;
        }
    }

    else if (x == 0) { 
        if (y == 125) {
            cout << "250.00 0.00";
        }

        else if (y < 125) {
            res_x = 31250 / (250 - y);
            res_y = 250 - res_x;
            cout << res_x << " " << res_y;
        }

        else {
            res_x = 31250 / y;
            cout << res_x << " " << "0.00";
        }
    }

    else {
        if (x == 125 && y == 125) {
            cout << "0.00 0.00";
        }

        else if (x < 125) {
            res_x = 125 * (y - x) / y;
            cout << res_x << " " << "0.00";
        }

        else {
            res_y = 125 * (x - y) / x;
            cout << "0.00" << " " << res_y;
        }
    }
    return 0;
}