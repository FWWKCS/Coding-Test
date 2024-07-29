#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

long long S = 0;

int main() {
    FASTIO;
    int N; cin >> N;
    long long maxD = -1;
    for (int i = 0; i < N; i++) {
        long long x; cin >> x;
        S += x;
        maxD = max(maxD, x);
    }

    if (N == 1 && maxD == 1) cout << "Happy";
    else if (S/2 >= maxD) cout << "Happy";
    else cout << "Unhappy";
}