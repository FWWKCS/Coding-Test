#include <bits/stdc++.h>
using namespace std;

int koong(vector<unsigned long long>& F, int n) {
    if (F[n] != 0) return F[n];

    if (n < 2) F[n] = 1;
    else if (n == 2) F[n] = 2;
    else if (n == 3) F[n] = 4;
    else F[n] = F[n-1] + F[n-2] + F[n-3] + F[n-4];

    return F[n];
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t; cin >> t;
    int n;
    vector<unsigned long long> F(68, 0);
    for (int i = 0; i <= 67; i++) koong(F, i);

    for (int i = 0; i < t; i++) {
        cin >> n;
        cout << F[n] << '\n';
    }
}