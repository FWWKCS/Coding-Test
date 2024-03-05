#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    double price;
    for (int i = 0; i < N; i++) {
        cin >> price;
        cout << fixed << setprecision(2) << '$' << price * 0.8 << '\n';
    }
}