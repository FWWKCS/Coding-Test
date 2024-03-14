#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, T; cin >> n >> T;
    int x, total = 0, count = 0;
    int i;
    for (i = 0; i < n; i++) {
        cin >> x;
        if (total + x <= T) total += x;
        else {
            cout << i;
            return 0;
        }
    }

    cout << i;
}