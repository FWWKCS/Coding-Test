#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int K; cin >> K;
    for (int x = 0; x < K; x++) {
        int P, M;
        cin >> P >> M;
        
        set<int> S;
        int seat;
        for (int i = 0; i < P; i++) {
            cin >> seat;
            S.insert(seat);
        }
        cout << P - S.size() << '\n';
    }
}