#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ll = long long;

ll x, y;

int main() {
    FASTIO;

    int n; cin >> n;
    while (n--) {
        ll m; cin >> m;

        for (x = 0; x < 60; x++) {
            for (y = x; y < 60; y++) {
                if ((1LL << x)+(1LL << y)==m) {
                    cout << x << ' ' << y << '\n'; 
                    break;
                }
            }
        }
    }
}