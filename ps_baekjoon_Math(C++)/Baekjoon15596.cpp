#include <vector>

using namespace std;

long long sum(std::vector<int> &a){
    long long ans = 0;

    for (auto j = a.begin(); j != a.end(); j++) {
        ans += *j;
    }
    return ans;
}