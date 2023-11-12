#include <bits/stdc++.h>
using namespace std;

int main() {
    int alphabet[26];
    // 초기화
    for (int i = 0; i < 26; i++) alphabet[i] = 0;
    string S;

    cin >> S;
    for (int i = 0; i < S.length(); i++) {
        alphabet[int(S[i])-97]++;
    }
    
    for (int i = 0; i < 26; i++) {
        cout << alphabet[i] << " ";
    }
}