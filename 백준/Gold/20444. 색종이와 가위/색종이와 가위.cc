#include <iostream>
using namespace std;
using ll = long long;

ll n, k;

ll binSearch() {
    ll C = k - (n+1);
    ll s = 0, e = n;
    ll res;
    while (s <= e) {
        ll y = (s + e) / 2;
        ll x = n - y;
        if (y * x == C) return y;
        else if (y * x < C) s = y + 1;
        else e = y - 1;
    }

    return -1;
}

int main() {
    cin >> n >> k;

    // x+y = n 이고, xy = k-(n+1) 인 x나 y중 하나를 탐색
    cout << (binSearch() == -1 ? "NO" : "YES");
}
