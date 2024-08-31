#include <iostream>
#include <vector>
#include <set>
#define INF 1'000'000'009
using namespace std;

int main() {
    set<int> subN;
    int N, M; cin >> N >> M;
    vector<int> woks;
    vector<int> dp(N+1, INF);

    for (int i = 0; i < M; i++) {
        int x; cin >> x;
        woks.push_back(x);
    }

    // 웍들 중 2개를 사용해 가능한 그릇 체크
    for (int i = 0; i < M-1; i++) {
        for (int j = i+1; j < M; j++) {
            subN.insert(woks[i]);
            subN.insert(woks[j]);
            subN.insert(woks[i] + woks[j]);
        }
    }
    
    for (auto x : subN) {
        if (x <= N) dp[x] = 1;
    }

    for (int i = 1; i <= N; i++) {
        for (auto x : subN) {
            if (i - x > 0) {
                dp[i] = min(dp[i], dp[i-x]+1);
            }
        }
    }

    if (dp[N] >= INF) cout << -1;
    else cout << dp[N];
}