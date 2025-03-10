#include <iostream>
#include <math.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

int main() {
    FASTIO;

    int n; cin >> n;
    while (n--) {
        ll m; cin >> m;

        ll x = 0, y = 0;
        ll tx, ty;

        ll dist = 1e18;

        for (tx = 0; tx < 60; tx++) {
            for (ty = tx; ty < 60; ty++) {
                ll res = (1LL << tx)+(1LL << ty);
                if (abs(res-m) < dist) {
                    x = tx, y = ty;
                    dist = abs(res-m);
                }
            }
        }

        cout << x << ' ' << y << '\n';
    }
}