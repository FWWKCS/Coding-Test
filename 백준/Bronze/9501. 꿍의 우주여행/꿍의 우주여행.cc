#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int N;
    double D;
    double v, f, c;
    for (int i = 0; i < T; i++) {
        int count = 0;
        cin >> N >> D;
        for (int j = 0; j < N; j++) {
            cin >> v >> f >> c;
            
            if (D / v * c <= f) count++;
        }

        cout << count << '\n';
    }
}