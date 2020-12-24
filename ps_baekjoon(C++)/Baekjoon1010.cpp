#include <iostream>

using namespace std;
using LL = long long;

LL dp(int N, int M) {
    LL solution = 0;
    
    if (N == M) {
        solution += 1;
    }

    else if (N == 1) {
        solution += M;
    }

    else {
        for (int i = N - 1; i < M; i++) {
          solution += dp(N-1, i);
        }
    }
    
    return solution;
}

int main() {
    int T;
    int N, M;
    cin >> T;

    pair<int, int>* pair_arr = new pair<int, int>[T]; 

    for(int i = 0; i < T; i++) {
        cin >> N >> M;
        pair_arr[i].first = N;
        pair_arr[i].second = M;
    }

    for(int i = 0; i < T; i++) {
        cout << dp(pair_arr[i].first, pair_arr[i].second) << endl;
    }

    delete pair_arr;
}