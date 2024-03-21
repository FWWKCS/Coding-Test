#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int a, b, c;
    char opr;
    bool add;
    for (int k = 1; k <= n; k++) {
        cin >> a;
        cin >> opr;

        if (opr == '+') add = true;
        else add = false;

        cin >> b;
        cin >> opr >> c;

        if (add) {
            if (a+b == c) cout << "Case " << k << ": YES\n";
            else cout << "Case " << k << ": NO\n";
        }
        else {
            if (a-b == c) cout << "Case " << k << ": YES\n";
            else cout << "Case " << k << ": NO\n";    
        }
    }

}