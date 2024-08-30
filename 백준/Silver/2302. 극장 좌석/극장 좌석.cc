#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int dp[N+1] = {0, };
    int M; cin >> M;
    bool vip[N+1] = {false, };
    while (M--) {
        int x; cin >> x;
        vip[x] = true;
        if (x < N) vip[x+1] = true;
    }

    dp[0] = 1, dp[1] = 1;
    for (int i = 2; i <= N; i++) {
        if (vip[i]) dp[i] = dp[i-1];
        else dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[N];
}