#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    vector<int> count(26, 0);

    while (getline(cin, S)) {
        if (S == "EOF") break;
        for (int i = 0; i < S.length(); i++) {
            if (S[i] != ' ') count[int(S[i])-97]++;
        } 
    }

    string answer = "";
    int total = 0;

    for (int i = 0; i < 26; i++) {
        if (count[i] > total) {
            answer = char(i+97);
            total = count[i];
        }
        else if (count[i] == total) answer += char(i+97);
    }

    cout << answer;
}