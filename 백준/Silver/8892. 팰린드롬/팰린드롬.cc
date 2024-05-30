#include <iostream>
#include <vector>
using namespace std;

bool valid(string A, string B) {
    string X = A + B;
    
    int s = 0, e = X.length()-1;

    while (s < e) {
        if (X[s] != X[e]) return false;

        s++; e--;
    }

    return true;
}


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    vector<string> S;
    for (int x = 0; x < T; x++) {
        int k; cin >> k;
        string input;
        for (int i = 0; i < k; i++) {
            cin >> input;
            S.push_back(input);
        }   

        bool found = false;
        string F;
        for (int i = 0; i < S.size()-1; i++) {
            for (int j = i+1; j < S.size(); j++) {
                if (valid(S[i], S[j])) {
                    F = S[i]+S[j];
                    found = true;
                    break;
                } 
                else if (valid(S[j], S[i])) {
                    F = S[j]+S[i];
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        if (found) cout << F << '\n';
        else cout << 0 << '\n'; 

        S.clear();
    }
}