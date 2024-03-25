#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    while (true) {
        cin >> N;
        if (N == 0) break;

        cout << (2*N+1) * (N+1) * N / 6 << '\n';
    }
}