#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    double x, y;
    string line;
    while (getline(cin, line)) {

        if (line == "EOF") break;
        istringstream is(line);

        is >> x >> y;
        cout << fixed << setprecision(2) << x / y << '\n';
    }
}