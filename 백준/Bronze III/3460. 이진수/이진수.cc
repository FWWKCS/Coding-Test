#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    int n;
    string bin = "";
    for (int i = 0; i < T; i++) {
        cin >> n;
        bin = bitset<32>(n).to_string();
        // cout << bin << '\n';
        for (int j = bin.length()-1; j > -1; j--) {
            if (bin[j] == '1') cout << 31 - j << ' ';
        }
        cout << '\n';
    }
}