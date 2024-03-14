#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int M; cin >> M;

    vector<int> index = {0, 1, 2, 3};

    int x, y, tmp;
    for (int i = 0; i < M; i++) {
        cin >> x >> y;
        tmp = index[x];
        index[x] = index[y];
        index[y] = tmp;
    }

    for (int i = 1; i <= 3; i++) {
        if (index[i] == 1) cout << i;
    }
}