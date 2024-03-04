#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int N, M;
    for (int i = 0; i < T; i++) {
        cin >> N >> M;
        cout << 2*M - N << ' ' << M - (2*M-N) << '\n';
    }
}