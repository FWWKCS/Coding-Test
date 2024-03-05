#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double total;
    int T; cin >> T;
    int A, B, C, D, E;
    for (int i = 0; i < T; i++) {
        total = 0;

        cin >> A;
        total += 350.34 * A;

        cin >> B;
        total += 230.90 * B;

        cin >> C;
        total += 190.55 * C;

        cin >> D;
        total += 125.30 * D;

        cin >> E;
        total += 180.90 * E;

        cout << fixed << setprecision(2) << '$' << total << '\n';
    }
}