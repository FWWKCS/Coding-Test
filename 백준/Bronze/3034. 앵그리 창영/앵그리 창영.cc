#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, W, H; cin >> N >> W >> H;
    int value;

    bool possible;

    for (int i = 0; i < N; i++) {
        possible = false;
        cin >> value;

        if (value <= W || value <= H) possible = true;
        else if (pow(value, 2) <= (pow(W, 2) + pow(H, 2))) possible = true;

        if (possible) cout << "DA\n";
        else cout << "NE\n";
    }

}