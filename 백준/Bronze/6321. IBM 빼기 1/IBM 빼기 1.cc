#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    string input;
    for (int i = 1; i <= n; i++) {
        cin >> input;
        cout << "String #" << i <<'\n';

        for (int k = 0; k < input.length(); k++) {
            if (input[k] == 'Z') cout << 'A';
            else cout << char(input[k]+1);
        }
        cout << "\n\n";
    }
}