#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    cin.ignore();
    string cryptogram;
    string key;
    map<char, char> mp;
    for (int i = 0; i < T; i++) {
        getline(cin, cryptogram);
        getline(cin, key);
        for (int k = 0; k < key.length(); k++) {
            mp.insert({char(k+65), key[k]});
        }

        for (int k = 0; k < cryptogram.length(); k++) {
            if (cryptogram[k] == ' ') {
                cout << " ";
                continue;
            }
            cout << mp[cryptogram[k]];
        } 
        cout << '\n';
        mp.clear();
    }
}