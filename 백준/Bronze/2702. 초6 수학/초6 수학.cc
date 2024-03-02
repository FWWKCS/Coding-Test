#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int a, b, GCD, LCM;
    for (int i = 0; i < T; i++) {
        cin >> a >> b;
        GCD = __gcd(a, b);
        LCM = a * b / GCD;
        cout << LCM << ' ' << GCD << '\n';
    }
}