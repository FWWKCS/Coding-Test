#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string s;
    int one, i;
    while (true) {
        cin >> s;
        if (s == "#") break;
        one = 0; 
        for (i = 0; i < s.length()-1; i++) {
            if (s[i] == '1') one++;
            cout << s[i];
        }

        if (s[i] == 'e') {
            if (one % 2 == 0) cout << "0\n";
            else cout << "1\n"; 
        }
        else if (s[i] == 'o') {
            if (one % 2 == 0) cout << "1\n";
            else cout << "0\n";
        }
    }
}