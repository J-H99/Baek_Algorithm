#include <iostream>
#include <algorithm>

using namespace std;

bool compare(int x, int y) {
    return x < y;
}

int main() {
    int N;
    double sum = 0;
    cin >> N;

    int* score = new int[N];
    double* res = new double[N];
    for (int i = 0; i < N; i++) {
        cin >> score[i];
    }

    sort(score, score + N, compare);
    for (int i = 0; i < N; i++) {
        res[i] = (score[i] / (double)score[N-1]) * 100;
        sum += res[i];
    }

    cout << sum / N;

}