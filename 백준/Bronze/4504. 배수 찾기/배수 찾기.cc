#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n; cin >> n;
    int input;
    while (true) {
        cin >> input;
        if (input == 0) break;

        if (input % n == 0) cout << input << " is a multiple of " << n << ".\n";
        else cout << input << " is NOT a multiple of " << n << ".\n";
    }
}