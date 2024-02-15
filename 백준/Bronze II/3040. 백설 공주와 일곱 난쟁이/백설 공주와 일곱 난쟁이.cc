#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> height(9);
    for (int i = 0; i < 9; i++) cin >> height[i];

    bool found = false;
    int a, b;
    int total = 0;
    for (int i = 0; i < 8; i++) {
        for (int j = i+1; j < 9; j++) {
            total = 0;
            for (int x = 0; x < 9; x++) {
                if (x == i || x == j) continue;
                total += height[x];
            }
            if (total == 100) {
                a = i; b = j;
                break;
            }
        }
        if (found) break;
    }

    for (int x = 0; x < 9; x++) {
        if (x != a && x != b) cout << height[x] << '\n';
    }
}