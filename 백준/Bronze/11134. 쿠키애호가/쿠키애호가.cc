#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int N, C;
    for (int i = 0; i < T; i++) {
        cin >> N >> C;
        if (N % C == 0) cout << N / C << '\n';
        else cout << N / C + 1 << '\n';
    }
}