#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string pre, current; cin >> pre;
    bool rise = false, fall = false;
    for (int i = 1; i < N; i++) {
        cin >> current;

        if (pre > current) fall = true;
        else rise = true;

        pre = current;
    }

    if (!rise && fall) cout << "DECREASING";
    else if (!fall && rise) cout << "INCREASING";
    else cout << "NEITHER";
}