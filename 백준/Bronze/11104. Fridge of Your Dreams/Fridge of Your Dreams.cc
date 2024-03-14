#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string bin;
    int dec;
    for (int i = 0; i < n; i++) {
        dec = 0;
        cin >> bin;
        for (int k = 0; k < bin.length(); k++) {
            dec += stoi(bin.substr(k, 1)) * pow(2, 23-k);
        }
        cout << dec << '\n';
    }
}