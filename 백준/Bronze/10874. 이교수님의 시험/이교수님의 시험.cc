#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int x;
    bool retry;
    for (int i = 1; i <= N; i++) {
        retry = true;
        for (int k = 1; k <= 10; k++) {
            cin >> x;
            if (x != ((k-1)%5)+1) retry = false;
        }

        if (retry) cout << i << '\n';
    }
}