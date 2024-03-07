#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int a;
    int s, e;
    string x;

    bool reflect;
    for (int i = 0; i < T; i++) {
        cin >> a;

        reflect = true;

        x = to_string(a);
        reverse(x.begin(), x.end());

        a += stoi(x);
        x = to_string(a);

        s = 0, e = x.length()-1;
        while (s < e) {
            if (x[s] != x[e]) {
                reflect = false;
                break;
            }
            s++; e--;
        }

        if (reflect) cout << "YES\n";
        else cout << "NO\n";
    }
}