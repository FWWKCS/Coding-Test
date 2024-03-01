#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int a, b;
    string plain;
    for (int k = 0; k < T; k++) {
        cin >> a >> b;
        cin >> plain;

        for (int i = 0; i < plain.length(); i++) {
            int X = int(plain[i]) - 65;
            cout << char(((a*X + b) % 26) + 65);
        }
        cout << '\n';
    }
}