#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, P;
    while (true) {
        cin >> N;
        if (N == 0) break;
        
        cin >> P;
        int s = 1, e = N;

        while (true) {
            if (P == s || P == s+1 || P == e-1 || P == e) {
                vector<int> page = {s, s+1, e-1, e};
                for (int i = 0; i < 4; i++) {
                    if (page[i] == P) continue;
                    cout << page[i] << ' ';
                }
                cout << '\n';
                break;
            }
            else {
                s += 2; e -= 2;
            }
        }
    }
}