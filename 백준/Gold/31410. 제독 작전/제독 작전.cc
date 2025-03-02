#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main() {
    FASTIO;

    ll N; cin >> N;
    vector<pair<ll, ll>> info(N+1);
    ll P = 0;
    ll L = 0, R = 0;
    for (int i = 1; i <= N; i++) {
        cin >> info[i].first >> info[i].second;
        P += info[i].second;
    }

    sort(info.begin()+1, info.end());
    L = (N-1)*info[N].first - info[1].first;
    R = -(N-1)*info[1].first + info[N].first;
    for (int i = 2; i < N; i++) {
        L -= info[i].first;
        R += info[i].first;
    }

    L += P, R += P;

    ll answer = LONG_LONG_MAX;
    // k = 1
    answer = min(answer, 
        min(L-(info[1].second + info[N].first - info[1].first), 
            R-(info[1].second + (N-1)*(info[2].first - info[1].first)))
    );

    // 1 < k < N
    for (int k = 2; k < N; k++) {
        ll x = info[k].first, p = info[k].second;
        answer = min(answer, 
            min(L-(p + info[N].first - x), R-(p + x - info[1].first)));
    }

    // k = N
    answer = min(answer,
        min(L-(info[N].second + (N-1)*(info[N].first - info[N-1].first)),
            R-(info[N].second + info[N].first - info[1].first))
    );

    cout << answer;
}