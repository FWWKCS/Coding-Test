#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    string X, Y;
    for (int k = 0; k < T; k++) {
        cin >> X >> Y;
        cout << "Distances: ";
        for (int i = 0; i < X.length(); i++) {
            if (int(X[i]) <= int(Y[i])) cout << int(Y[i]) - int(X[i]) << ' ';
            else cout << (int(Y[i]) - 64) + 26 - (int(X[i]) - 64) << ' ';
        }
        cout << '\n';
    }
}