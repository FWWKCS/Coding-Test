#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    if (N == 1) {
        cout << 0;
        return 0;
    }

    int att[N]; 
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        att[i] = x;
    }

    int V = 0;
    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++) {
        for (int k = i-1; k > -1; k--) {
            if (att[k] > att[i]) dp[i] = max(dp[i], dp[k]+1);
        }
        V = max(V, dp[i]);
    }

    cout << N-V;
}