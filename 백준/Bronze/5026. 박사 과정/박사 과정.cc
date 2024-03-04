#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    string S;
    for (int i = 0; i < N; i++) {
        int total = 0;
        string num = "";
        cin >> S;
        S += '+';
        if (S[0] == 'P') {
            cout << "skipped\n";
            continue;
        }
        for (int k = 0; k < S.length(); k++) {
            if (S[k] == '+') {
                total += stoi(num);
                num = "";
            }
            else num += S[k];
        }
        cout << total << '\n';
    }
}