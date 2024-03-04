#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    set<char> A;
    while (true) {
        getline(cin, S);
        if (S[0] == '*') break;

        for (int i = 0; i < S.length(); i++) {
            if (S[i] != ' ') A.insert(S[i]);
        }
        
        if (A.size() == 26) cout << "Y\n";
        else cout << "N\n";
        A.clear();
    }
}