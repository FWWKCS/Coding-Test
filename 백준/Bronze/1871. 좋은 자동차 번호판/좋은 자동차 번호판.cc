#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    int value = 0;
    string panel;
    for (int k = 0; k < N; k++) {
        cin >> panel;
        for (int x = 0; x < 3; x++) value += (int(panel[x])-65) * pow(26, 2-x);
        if (abs(value-stoi(panel.substr(4, 4))) <= 100) cout << "nice\n";
        else cout << "not nice\n";

        value = 0;
    }
}