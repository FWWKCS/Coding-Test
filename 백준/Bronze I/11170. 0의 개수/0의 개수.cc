#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    int N, M, count;
    string x;
    for (int k = 0; k < T; k++) {
        cin >> N >> M;
        count = 0;
        for (int i = N; i <= M; i++) {
            x = to_string(i);
            for (int j = 0; j < x.length(); j++) {
                if (x[j] == '0') count++;
            }
        }
        cout << count << '\n';
    }
}