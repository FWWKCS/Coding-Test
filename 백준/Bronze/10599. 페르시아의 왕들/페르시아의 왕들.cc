#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c, d;
    while (true) {
        cin >> a >> b >> c >> d;
        if (a == 0 && b == 0 && c == 0 && d == 0) break;

        cout << c - b << ' ' << d - a << '\n';
    }
}