#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int d;
    for (int i = 0; i < T; i++) {
        cin >> d;
        int t = 0;
        while (true) {
            if (t+pow(t, 2) > d) {
                t--; 
                break;
            }
            t++;
        }
        cout << t << '\n';
    }
}