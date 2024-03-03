#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0); 
    cout.tie(0);

    int t, n; cin >> t;
    for (int i = 0; i < t; i++) {
        int s1 = 0, s2 = 0;
        char p1, p2;
        cin >> n;
        for (int k = 0; k < n; k++) {
            cin >> p1 >> p2;
            if (p1 == 'R') {
                if (p2 == 'S') s1++;
                else if (p2 == 'P') s2++;
            } 
            else if (p1 == 'S') {
                if (p2 == 'P') s1++;
                else if (p2 == 'R') s2++; 
            }
            else {
                if (p2 == 'R') s1++;
                else if (p2 == 'S') s2++;
            }
        }

        if (s1 > s2) cout << "Player 1\n";
        else if (s1 < s2) cout << "Player 2\n";
        else cout << "TIE\n";
    }
}