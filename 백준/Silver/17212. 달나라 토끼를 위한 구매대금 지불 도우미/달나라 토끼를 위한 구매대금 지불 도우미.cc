#include <iostream>
#include <vector>
#define INF 100'000
using namespace std;

int main() {
    int N; cin >> N;
    int coin[4] = {1, 2, 5, 7};
    vector<int> dp(N+1, INF);
    dp[0] = 0;
    for (int k = 1; k <= N; k++) {
        for (int x = 0; x < 4; x++) {
            if (k < coin[x]) break;

            dp[k] = min(dp[k], dp[k-coin[x]] + 1);
        }
    }

    cout << dp[N];
}