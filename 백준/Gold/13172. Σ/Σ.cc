#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MOD 1'000'000'007
using namespace std;
using ll = long long;

ll divide(ll base, ll exp) {
    // cout << base << ' ' << exp << '\n';
    if (exp == 1) return base; 
    ll result =  divide(base, exp/2) % MOD;

    if (exp % 2)  // 홀수
        return (((result * result) % MOD) * base) % MOD;
    else 
        return (result * result) % MOD;   
}

int main() {
    FASTIO;

    int M; cin >> M;
    ll answer = 0;
    while (M--) {
        ll N, S; cin >> N >> S;
        answer = (answer + ((S * divide(N, MOD-2)) % MOD)) % MOD;
    }

    cout << answer;
}