#include <bits/stdc++.h>
using namespace std;

int main(void) {
    string S; cin >> S;
    int joi = 0, ioi = 0;
    for (int i = 0; i < S.length()-2; i++) {
        if (S[i] == 'J') {
            if (S[i+1] == 'O' && S[i+2] == 'I') joi++;
        }
        else if (S[i] == 'I') {
            if (S[i+1] == 'O' && S[i+2] == 'I') ioi++;
        }
    }

    cout << joi << '\n' << ioi;
}