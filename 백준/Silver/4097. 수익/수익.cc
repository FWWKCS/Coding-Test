#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    int N;
    while (cin >> N) {
        if (N == 0) break;
        
        int arr[N] = {0, };
        for (int i = 0; i < N; i++) {
            int x; cin >> x;
            arr[i] = x;
        }

        long long dp[N] = {0, };
        dp[0] = arr[0];

        long long maxV = -2'500'000'001;
        for (int i = 1; i < N; i++) {
            dp[i] = max(dp[i-1]+arr[i], (long long)arr[i]);
            maxV = max(maxV, dp[i]);
        }

        cout << maxV << '\n';
    }
}