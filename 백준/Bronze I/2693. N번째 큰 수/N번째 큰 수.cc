#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> num(10);
    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        for (int k = 0; k < 10; k++) cin >> num[k];
        sort(num.rbegin(), num.rend());
        cout << num[2] << '\n';
    }
}