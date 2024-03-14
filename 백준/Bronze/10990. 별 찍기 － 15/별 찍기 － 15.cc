#include <bits/stdc++.h>
using namespace std;

int main() {
    int n; cin >> n; 

    for (int l = 1; l <= n; l++) {
        // blank 1
        for (int b = n-l; b > 0; b--) cout << ' ';
        cout << '*';

        if (l == 1) {
            cout << '\n';
            continue;
        };

        // blank 2
        for (int b = 2*l-3; b > 0; b--) cout << ' ';
        cout << "*\n";
    }
}