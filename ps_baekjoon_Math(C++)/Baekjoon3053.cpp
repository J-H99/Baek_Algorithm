#include <iostream>

using namespace std;

int main() {
    double R;
    cin >> R;
    cout << fixed;
    cout.precision(6);
    cout << R * R * (3.14159265359) << endl;
    cout << R * R * 2 << endl; 
    return 0;
}