#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int day[N+1] = {0, };

    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        day[i] = x;
    }

    int maxV = 0;
    int dp[N+1] = {0, };
    for (int i = 1; i <= N; i++) {
        for (int k = i-1; k > -1; k--) {
            if (day[k] < day[i]) dp[i] = max(dp[i], dp[k] + day[i]); 
        }
        maxV = max(maxV, dp[i]);
    }

    cout << maxV;
}