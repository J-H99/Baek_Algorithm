#include <iostream>

using namespace std;

int main() {
    int A, B;

    cin >> A >> B;
    while((A > 0 && A < 10) && (B > 0 && B < 10) && (!cin.eof())) {
        cout << A + B << endl;
        cin >> A >> B;
    }

    return 0;
}