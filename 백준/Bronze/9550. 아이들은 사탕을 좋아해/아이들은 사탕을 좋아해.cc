#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int N, K, x, total;
    for (int i = 0; i < T; i++) {
        cin >> N >> K;
        total = 0;
        for (int j = 0; j < N; j++) {
            cin >> x;
            total += x / K;
        }
        cout << total << '\n';
    }
}