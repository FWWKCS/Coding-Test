#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S; cin >> S;
    vector<string> suffix;

    for (int i = 0; i < S.length(); i++) {
        suffix.push_back(S.substr(i, S.length()));
    }

    sort(suffix.begin(), suffix.end());
    for (int i = 0; i < suffix.size(); i++) cout << suffix[i] << '\n';
}