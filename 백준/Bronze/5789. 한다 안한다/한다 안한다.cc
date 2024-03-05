#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string S;
    int len;
    for (int i = 0; i < N; i++) {
        cin >> S;
        len = S.length();

        if (S[len/2] == S[len/2 - 1]) cout << "Do-it\n";
        else cout << "Do-it-Not\n";
    }
}