#include <bits/stdc++.h>
using namespace std;

int Rev(string X) {
    reverse(X.begin(), X.end());
    return stoi(X);
}

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X, Y;
    cin >> X >> Y;

    cout << Rev(to_string(Rev(X)+Rev(Y)));
}