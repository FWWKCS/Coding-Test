#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a, b, c;
    int ap, gp;
    while (true) {
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0) break;

        if (b-a == c-b) {
            ap = b-a;
            cout << "AP " << c+ap << '\n';
        }
        else {
            gp = b/a;
            cout << "GP " << c * gp << '\n'; 
        }
    }
}