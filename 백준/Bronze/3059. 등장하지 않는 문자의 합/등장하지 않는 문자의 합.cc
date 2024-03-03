#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int i, T; cin >> T;
    string S;

    set<char> alphabet;
    for (i = 65; i < 91; i++) alphabet.insert(char(i));

    set<char> inS;
    set<char> difference;
    for (i = 0; i < T; i++) {
        int k, total = 0;
        cin >> S;
        for (k = 0; k < S.length(); k++) inS.insert(S[k]);
        
        set_difference(alphabet.begin(), alphabet.end(), inS.begin(), inS.end(), inserter(difference, difference.begin()));
        for (auto x : difference) total += int(x);
        cout << total << '\n';
        inS.clear();
        difference.clear();
    }
}