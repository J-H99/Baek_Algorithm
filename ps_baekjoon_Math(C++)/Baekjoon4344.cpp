#include <iostream>
#include <vector>

using namespace std;

int main() {
    int C, N, Value, sum, cnt = 0;
    cin >> C;

    vector<int>* score = new vector<int>[C];
    double* avg = new double[C];
    int* num = new int[C];

    for(int i = 0; i < C; i++) {
        cin >> num[i];
        
        for (int j = 0; j < num[i]; j++){
            cin >> Value;
            score[i].push_back(Value);
        }
    }

    for(int i = 0; i < C; i++) {
        sum = 0;
        for (auto j = score[i].begin(); j != score[i].end(); j++) {
            sum += *j;
        }

        avg[i] = sum / (double)num[i];
    }


    cout << fixed;
    cout.precision(3);
    for(int i = 0; i < C; i++) {
        cnt = 0;
        for (auto j = score[i].begin(); j != score[i].end(); j++) {
            if (*j > avg[i]) {
                cnt++;
            }
        }
        
        cout << (cnt / (double)num[i])*100 << "%" << endl;
    }

    delete score;
    delete avg;
}