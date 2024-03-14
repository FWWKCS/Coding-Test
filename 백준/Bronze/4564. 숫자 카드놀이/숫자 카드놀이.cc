#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    while (true) {
        cin >> S;
        if (S == "0") break;

        cout << S << ' ';
        while (S.length() != 1) {
            int mul = 1;
            for (int x = 0; x < S.length(); x++) mul *= stoi(S.substr(x, 1));
            cout << mul << ' ';
            S = to_string(mul);
        }
        cout << '\n';
    }
}