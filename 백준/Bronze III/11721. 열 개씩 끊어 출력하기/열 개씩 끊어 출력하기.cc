#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string word;
    cin >> word;

    for (int i = 0; i < word.length(); i++) {
        if (i != 0 && i % 10 == 0) cout << '\n';
        cout << word[i]; 
    }
}