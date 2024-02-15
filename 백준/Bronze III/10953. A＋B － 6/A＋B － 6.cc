#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int i;
    string input;
    for (i = 0; i < T; i++) {
        cin >> input;
        cout << stoi(input.substr(0, 1)) + stoi(input.substr(2, 1)) << '\n';
    }
}