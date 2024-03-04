#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; cin >> S;
    int total = 0, s = 0, e = 1;
    while (e < S.length()) {
        if (S[e] == ',') {
            total += stoi(S.substr(s, e-s));
            s = e + 1;
            e = s + 1;
        }
        e++;
    }
    total += stoi(S.substr(s, e-s));
    cout << total;
}