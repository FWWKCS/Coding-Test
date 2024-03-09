#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    int i, total;
    while (true) {
        getline(cin, S);
        if (S == "#") break;

        total = 0;
        for (i = 0; i < S.length(); i++) {
            if ('A' <= S[i] && S[i] <= 'Z') total += (i+1) * (int(S[i]) - 64);
        }

        cout << total << '\n';
    }
}