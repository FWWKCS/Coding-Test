#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int s, n; cin >> s; cin >> n;
        int option, cost, total = 0;
        for (int j = 0; j < n; j++) {
            cin >> option >> cost;
            total += option * cost;
        }
        cout << s+total << '\n';
    }
}