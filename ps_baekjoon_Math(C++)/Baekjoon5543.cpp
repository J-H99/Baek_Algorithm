#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int burger1, burger2, burger3, coke, soda;
    cin >> burger1 >> burger2 >> burger3 >> coke >> soda;

    cout << min(burger1, min(burger2, burger3)) + min(coke, soda) - 50;
    return 0;
}