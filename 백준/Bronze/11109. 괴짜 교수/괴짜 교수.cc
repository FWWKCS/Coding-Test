#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int d, n, s, p;
    int sr = 0, pr = 0; 
    for (int i = 0; i < T; i++) {
        cin >> d >> n >> s >> p;
        sr = n * s;
        pr = d + n * p;

        if (sr > pr) cout << "parallelize\n";
        else if (sr < pr) cout << "do not parallelize\n";
        else cout << "does not matter\n";
    }
}