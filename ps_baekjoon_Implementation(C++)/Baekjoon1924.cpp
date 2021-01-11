#include <iostream>
#include <vector>

using namespace std;

int main() {
    int x, y, plus = 0;
    cin >> x >> y;

    string DAY[7] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};
    int Day[7] = {0, 1, 2, 3, 4, 5, 6};
    int day[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> date;
    date.push_back(Day[0]);

    for (int i = 1; i < x; i++) {
        date.push_back(Day[(plus + day[i - 1]) % 7]);
        plus = (plus + day[i - 1]) % 7;
    }

    int curr_month = date.back();
    for (int i = 1; i <= y; i++) {
        curr_month++;
        if (curr_month == 8) {
            curr_month = 1;
        }
    }

    cout << DAY[curr_month - 1];
    return 0;
}