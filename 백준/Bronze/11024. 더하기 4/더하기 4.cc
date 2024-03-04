#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int T; cin >> T;
    cin.ignore();
    string S;
    for (int i = 0; i < T; i++) {
        int total = 0;
        string num = "";
        getline(cin, S);
        S += ' ';
        for (int k = 0; k < S.length(); k++) {
            if (S[k] == ' ') {
                total += stoi(num);
                num = "";
            }
            else num += S[k];
            
        }
        cout << total << '\n';
    }
}