#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    map<char, int> info;
    string S;
    for (int i = 0; i < N; i++) {
        cin >> S;
        if (info.find(S[0]) != info.end()) info[S[0]]++;
        else info[S[0]] = 1;
    }

    string answer = "";
    for (auto x : info) {
        if (x.second >= 5) answer += x.first; 
    }

    if (answer.length() > 0) cout << answer;
    else cout << "PREDAJA";
}