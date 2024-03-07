#include <bits/stdc++.h>
using namespace std;

long long koong(vector<long long>& F, int n) {
    if (F[n] != 0) return F[n];

    if (n < 2) F[n] = 1;
    else if (n == 2) F[n] = 2;
    else if (n == 3) F[n] = 4;
    else F[n] = koong(F, n-1) + koong(F, n-2) + koong(F, n-3) + koong(F, n-4);

    return F[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    int n;
    vector<long long> F(68, 0);

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << koong(F, n) << '\n';
    }
}