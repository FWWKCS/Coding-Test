#include <iostream>
#include <vector>
#define MAX 33'333
#define MOD 1'000'000'009
using namespace std;
using ll = long long;

vector<ll> dp(MAX+1, 0);

int main() {
    dp[2] = 2;
    
    for (int i = 3; i <= MAX; i++) {
        dp[i] = (dp[i-1] * 3) % MOD;
    }
    
    int N; cin >> N;
    cout << dp[N];
}