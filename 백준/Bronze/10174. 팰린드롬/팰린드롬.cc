#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    cin.ignore();
    string target;
    
    for (int i = 0; i < N; i++) {
        getline(cin, target);
        for (int k = 0; k < target.length(); k++) target[k] = tolower(target[k]);

        bool right = true;
        int s = 0, e = target.length()-1;
        while (s < e) {
            if (target[s] != target[e]) {
                right = false;
                break;
            }
            s++; e--;
        }

        if (right) cout << "Yes\n";
        else cout << "No\n";
    }
}