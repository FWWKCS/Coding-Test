#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main() {
    FASTIO;

    int N, K; cin >> N >> K;
    int cur;
    vector<ll> sub;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (i == 0) cur = x;
        else {
            sub.push_back(x-cur);
            cur = x;
        }
    }

    sort(sub.begin(), sub.end());

    for (int i = 0; i < K-1; i++) {
        sub.pop_back();
    }

    ll answer = 0;
    for (auto x : sub) answer += x;
    cout << answer;
}