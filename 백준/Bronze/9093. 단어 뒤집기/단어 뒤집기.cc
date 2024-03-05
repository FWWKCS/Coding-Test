#include <bits/stdc++.h>
using namespace std;

void partial_reverse(string& S, int s, int e) {
    char tmp;
    while (s < e) {
        tmp = S[s];
        S[s] = S[e];
        S[e] = tmp;

        s++; e--;
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    cin.ignore();
    string S;
    int s, e;

    for (int i = 0; i < T; i++) {
        getline(cin, S);
        S += ' ';
        s = 0; e = 1;
        while (e <= S.length()) {
            if (S[e] == ' ') {
                partial_reverse(S, s, e-1);        
                s = e + 1;
                e = s + 1;
            } 
            else e++;
        }
        cout << S << '\n';
    }
}