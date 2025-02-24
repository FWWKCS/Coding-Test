#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int N; 
vector<ll> T;

int binSearch(ll target) {
    int s = 1, e = N, res = 0;

    while (s <= e) {
        int mid = (s+e) / 2;
        if (T[mid] <= target) {
            res = mid;
            s = mid + 1;
        } 
        else e = mid - 1;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> N;
    T.resize(N+1);
    for (int i = 1; i <= N; i++) cin >> T[i];

    vector<ll> B(N+1);
    for (int i = 1; i <= N; i++) cin >> B[i];    

    vector<ll> C(N+1);
    for (int i = 1; i <= N; i++) cin >> C[i];
    
    vector<ll> dp(N+1, 0);
    dp[1] = C[1];

    for (int i = 2; i <= N; i++) {
        if (T[i] - B[i] -1 < 1) dp[i] = max(dp[i-1], C[i]);
        else {
            int idx = binSearch(T[i]-B[i]-1);
            // cout << idx << '\n';
            dp[i] = max(dp[i-1], dp[idx]+C[i]);
        }
    }

    cout << dp[N];
}