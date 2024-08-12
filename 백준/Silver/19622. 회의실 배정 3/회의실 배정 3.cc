#include <iostream>
#include <vector>
#include <tuple>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;
    
    int N; cin >> N;
    vector<tuple<int, int, int>> M(1, make_tuple(0, 0, 0));
    for (int i = 0; i < N; i++) {
        int s, e, p; cin >> s >> e >> p;
        M.push_back(make_tuple(s, e, p));
    }

    int dp[N+1] = {0, };
    dp[1] = get<2>(M[1]);

    for (int i = 2; i <= N; i++) {
        dp[i] = max(dp[i-1], dp[i-2]+get<2>(M[i]));
    }

    cout << dp[N];
}