#include <iostream>
#include <vector>
#define INF 300'000
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> dp(N+1, INF);
    dp[0] = 0;

    vector<int> prefix(1, 1), cost(1, 1);
    int count = 2;
    while (cost.back() < 300'000) {
        prefix.push_back(prefix.back()+count);
        cost.push_back(prefix.back()+cost.back());
        count++;
    }

    cost.pop_back();
    
    for (int i = 1; i <= N; i++) {
        for (int k = 0; k < cost.size(); k++) {
            if (i < cost[k]) break;

            dp[i] = min(dp[i-cost[k]]+1, dp[i]);
        }
    }

    cout << dp[N];
}