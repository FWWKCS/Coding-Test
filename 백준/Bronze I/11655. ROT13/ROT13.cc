#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    getline(cin, S);

    int value;
    for (int i = 0; i < S.length(); i++) {
        // 대문자
        if ('A' <= S[i] && S[i] <= 'Z') {
            value = int(S[i]) + 13;
            if (value > 90) value -= 26;

            cout << char(value);
        }
        // 소문자
        else if ('a' <= S[i] && S[i] <= 'z') {
            value = int(S[i]) + 13;
            if (value > 122) value -= 26;

            cout << char(value);
        }
        // 공백
        else cout << S[i];
    }
}