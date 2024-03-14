#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    cin.ignore();
    string S;
    for (int i = 1; i <= N; i++) {
        getline(cin, S);
        
        vector<int> count(26, 0);

        for (int k = 0; k < S.length(); k++) {
            if ('A' <= S[k] && S[k] <= 'Z') count[S[k]-65]++;
            else if ('a' <= S[k] && S[k] <= 'z') count[S[k]-97]++;
        }

        // check pangram
        int value = 3;
        for (int x = 0; x < 26; x++) value = min(count[x], value);

        if (value >= 3) cout << "Case " << i << ": Triple pangram!!!\n";
        else if (value == 2) cout << "Case " << i << ": Double pangram!!\n";
        else if (value == 1) cout << "Case " << i << ": Pangram!\n";
        else cout << "Case " << i << ": Not a pangram\n";
    }
}