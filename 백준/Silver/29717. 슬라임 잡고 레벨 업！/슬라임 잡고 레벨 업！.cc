#include <iostream>
#define MAX 1e9
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;
using ll = long long;

int T;

ll binLev(ll exp) {
    ll s = 1, e = MAX;
    ll res;

    while (s <= e) {
        ll mid = (s+e)/2;
        if (mid*(mid+1) > exp) {
            res = mid;
            e = mid-1;
        }
        else s = mid+1;
    }

    return res;
}

int main() {
    FASTIO;
    cin >> T;
    while (T--) {
        ll N; cin >> N;

        ll exp = (N+1)*N/2;
        cout << binLev(exp) << '\n';
    }
}