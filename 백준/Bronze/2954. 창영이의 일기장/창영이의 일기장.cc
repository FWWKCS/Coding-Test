#include <bits/stdc++.h>
using namespace std;

int main() {
    string S; 
    getline(cin, S);
    set<char>vowel = {'a', 'e', 'i', 'o', 'u'};
    string answer = "";
    for (int i = 0; i < S.length(); i++) {
        if (vowel.find(S[i]) != vowel.end()) {
            answer += S[i];
            i += 2;
        } 
        else answer += S[i];
    }
    cout << answer;
}