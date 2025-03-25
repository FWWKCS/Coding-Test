#include <iostream>
#include <queue>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;
using ll = long long;

bool customSort(pair<ll, ll> &x, pair<ll, ll> &y) {
    if (x.second != y.second) return x.second < y.second;
    return x.first < y.first;
}

int main() {
    FASTIO;

    int N, A, B; cin >> N >> A >> B;
    priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>> pd;
    vector<pair<ll, ll>> st;

    ll P = 0, Q = 0;
    
    for (int i = 0; i < N; i++) {
        ll p, q; cin >> p >> q;
        st.push_back({p, q});
        pd.push({p-q, i});
    }
    
    ll answer = 0;
    for (int i = 0; i < N; i++) {
        ll sub = pd.top().first, idx = pd.top().second;
        
        if (i < A) {
            answer += st[idx].first;
            pd.pop();
        }
        else {
            answer += st[idx].second;
            pd.pop();
        }
    } 

    cout << answer;
}