#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int x;

    for (int i = 1; i <= T; i++) {
        vector<int> l;
        for (int k = 0; k < 3; k++) {
            cin >> x;
            l.push_back(x);
        }
        sort(l.begin(), l.end());

        if (l[0]+l[1] <= l[2]) cout << "Case #" << i << ": invalid!\n";
        else if (l[0] == l[1] && l[1] == l[2]) cout << "Case #" << i << ": equilateral\n";
        else if (l[0] == l[1] || l[1] == l[2]) cout << "Case #" << i << ": isosceles\n";
        else cout << "Case #" << i << ": scalene\n";
    }
}