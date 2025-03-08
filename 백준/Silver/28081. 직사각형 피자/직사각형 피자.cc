#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

ll W, H, K; 
vector<ll> X, Y = {0};

ll binSearch(ll v) {
    int s = 0, e = Y.size()-1;
    ll res = 0;

    while (s <= e) {
        int mid = (s+e)/2;
        if (Y[mid] <= v) {
            res = mid;
            s = mid+1;
        }
        else e = mid-1;
    }

    return res;
}

int main() {
    FASTIO;

    cin >> W >> H >> K;

    int N; cin >> N;
    ll cur = 0;
    while (N--) {
        ll y; cin >> y;
        Y.push_back(y-cur);
        cur = y;
    }
    Y.push_back(H-cur);

    int M; cin >> M;
    cur = 0;
    while (M--) {
        ll x; cin >> x;
        X.push_back(x-cur);
        cur = x;
    }
    X.push_back(W-cur);

    
    sort(X.begin(), X.end());
    sort(Y.begin(), Y.end());

    ll answer = 0;
    for (ll x : X) answer += binSearch(K/x);

    cout << answer;
}