#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int T; cin >> T;
    int idx;
    string word = "";
    for (int i = 0; i < T; i++) {
        cin >> idx >> word;
        for (int j = 0; j < word.length(); j++) {
            if (j == idx-1) continue;
            cout << word[j];
        }
        cout << '\n';
    }
}