#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std; 
using ll = long long;

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    vector<ll> prefix(2*N+1);
    prefix[0] = prefix[1] = 0;

    for (int i = 2; i <= N+1; i++) cin >> prefix[i];
    for (int i = N+2; i <= N*2; i++) prefix[i] = prefix[i-N];

    for (int i = 1; i <= N*2; i++) prefix[i] += prefix[i-1];

    ll answer = 0;
    ll cycle = prefix[N+1];
    while (M--) {
        ll p, r, c; cin >> p >> r >> c;

        ll k;
        if (max(c-prefix[p], 0LL) % cycle == 0) k = max(c-prefix[p], 0LL)/cycle;
        else k = (max(c-prefix[p], 0LL)/cycle) + 1;
        
        ll delay = prefix[p] + cycle * k;

        ll move;
        if (p < r) move = prefix[r] - prefix[p];
        else move = prefix[r+N] - prefix[p];

        answer = max(answer, delay+move);
    }

    cout << answer;
}