#include <iostream>
#include <vector>
#include <map>
#define MAX 1e8 + 1
using namespace std;

int main() {
    int N, D; cin >> N >> D;

    vector<int> dp(D+1, MAX);
    map<int, vector<pair<int, int>>> rel;
    while (N--) {
        int S, E, L; cin >> S >> E >> L;

        if (E > D) continue;

        if (rel.find(E) != rel.end()) rel[E].push_back(make_pair(S, L));
        else rel[E] = {make_pair(S, L)};
    }

    dp[0] = 0;
    for (int i = 1; i <= D; i++) {
        // 지름길 검사
        if (rel.find(i) != rel.end()) {
            for (auto x : rel[i]) {
                dp[i] = min(dp[i], dp[x.first] + x.second);
            }
        }

        for (int k = i-1; k > -1; k--) {
            dp[i] = min(dp[i], dp[k] + (i-k));
        }
    }

    // for (auto x : dp) cout << x << ' ';
    cout << dp[D];
}