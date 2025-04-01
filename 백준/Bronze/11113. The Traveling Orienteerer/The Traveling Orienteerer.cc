#include <iostream>
#include <cmath>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
using ld = long double;

int n, m, p, i;
ld x, y;

ld getDist(pair<ld, ld>& x, pair<ld, ld>& y) {
    return sqrtl(powl(x.first-y.first, 2)+powl(x.second-y.second, 2));
}

int main() {
    FASTIO;
    cin >> n;
    vector<pair<ld, ld>> pos(n);
    for (auto &x : pos) cin >> x.first >> x.second;
    
    cin >> m;
    while (m--) {
        cin >> p;
        vector<int> seq(p);
        for (auto &i : seq) cin >> i;

        ld d = 0;
        for (int i = 1; i < p; i++) {
            d += getDist(pos[seq[i]], pos[seq[i-1]]);
        }

        cout << round(d) << '\n';
    }
    
}