#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;
    
    double* V = new double[N];
    double* DP = new double[N];
    for (int i = 0; i < N; i++) {
        cin >> V[i];
        DP[i] = V[i];
    }

    for (int i = 1; i < N; i++) {
        DP[i] = max(DP[i - 1] * V[i], V[i]);
    }

    cout << fixed;
    cout.precision(3);
    cout << *max_element(DP, DP + N);
    delete V; 
    delete DP;
    return 0;
}