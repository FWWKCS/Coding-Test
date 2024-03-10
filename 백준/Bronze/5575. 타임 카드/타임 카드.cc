#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int sh, sm, ss, eh, em, es;
    for (int i = 0; i < 3; i++) {
        cin >> sh >> sm >> ss >> eh >> em >> es;
        int total = (eh * 3600 + em * 60 + es) - (sh * 3600 + sm * 60 + ss);
        cout << total / 3600 << ' ';
        total %= 3600;
        cout << total / 60 << ' ';
        total %= 60;
        cout << total << '\n';
    }
}