#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    long long a, b;
    long long GCD, LCM;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        GCD = __gcd(a, b);
        LCM = a * b / GCD;
        cout << LCM << '\n';
    }
}