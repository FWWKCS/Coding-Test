#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    cin.ignore();
    string S;
    set<char> A;
    for (int i = 97; i < 97 + 26; i++) A.insert(char(i));
    set<char> B;
    for (int i = 0; i < N; i++) {
        getline(cin, S);
        for (int k = 0; k < S.length(); k++) {
            S[k] = tolower(S[k]);
            if ('a' <= S[k] && S[k] <= 'z') B.insert(S[k]);
        }

        set<char> C;
        set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(C, C.begin()));
        if (C.size() == 0) cout << "pangram";
        else {
            cout << "missing ";
            for (auto x : C) cout << x;
        }
        cout << '\n';

        B.clear();
        C.clear();
    }
}