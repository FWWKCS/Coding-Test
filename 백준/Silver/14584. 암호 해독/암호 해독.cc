#include <iostream>
#include <string>
using namespace std;

int main() {
    string cipher; cin >> cipher;
    int N; cin >> N;
    string words[N];
    for (int i = 0; i < N; i++) {
        string s; cin >> s;
        words[i] = s;
    }

    int pos = 0;
    while (pos < 26) {
        string key = "";
        for (int i = 0; i < 26; i++) {
            key.push_back(char((i+pos)%26 + 97));
        }
        // cout << key << '\n';

        string plain = "";
        for (char c : cipher) {
            plain.push_back(key[c - 'a']);
        }
        // cout << plain << '\n';

        for (string word: words) {
            if (plain.find(word) != string::npos) {
                cout << plain;
                return 0;
            }
        }

        pos++;
    }
}