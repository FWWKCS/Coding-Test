#include <iostream>
#define MAX 31
using namespace std;

int main() {
    int H, N; cin >> H >> N;

    long long dp[MAX] = {1, };

    for (int i = 0; i < MAX-1; i++) {
        dp[i+1] = dp[i] * (4*i + 2) / (i+2);
    }

    cout << dp[abs(H-N)];
}