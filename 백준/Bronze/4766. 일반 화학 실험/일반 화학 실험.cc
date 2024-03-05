#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string current, state; cin >> current;
    while (true) {
        cin >> state;
        if (state == "999") break;

        cout << fixed << setprecision(2) << stod(state) - stod(current) << '\n';
        current = state; 
    }
}