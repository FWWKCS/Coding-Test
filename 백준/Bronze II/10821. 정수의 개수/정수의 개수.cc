#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string S;
    cin >> S;
    int count = 1;
    for (int i = 0; i < S.length(); i++) {
        if (S[i] == ',') count++;
    }
    cout << count;
}