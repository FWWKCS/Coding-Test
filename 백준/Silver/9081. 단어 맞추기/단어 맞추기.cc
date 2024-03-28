#include <bits/stdc++.h>
using namespace std;

int main() {
    int T; cin >> T;
    string word;
    vector<char> w;
    
    for (int k = 0; k < T; k++) {
        cin >> word;
        for (int i = 0; i < word.length(); i++) w.push_back(word[i]);
        bool found = next_permutation(w.begin(), w.end());

        if (found) {
            for (int i = 0; i < word.length(); i++) cout << w[i];
            cout << '\n';
        }
        else cout << word << '\n';

        w.clear();
    }
}