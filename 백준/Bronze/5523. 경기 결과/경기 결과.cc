#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, a, b; cin >> N;
    int ca = 0, cb = 0;

    for (int i = 0; i < N; i++) {
        cin >> a >> b;
        if (a > b) ca++;
        else if (a < b) cb++;
    }
    cout << ca << ' ' << cb;
}