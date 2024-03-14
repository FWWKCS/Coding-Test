#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> g_info = {1, 2, 3, 3, 4, 10};
    vector<int> s_info = {1, 2, 2, 2, 3, 5, 10};

    int N; cin >> N;
    int G, S;
    for (int i = 1; i <= N; i++) {
        G = 0; S = 0;
        int v;
        for (int x = 0; x < 6; x++) {
            cin >> v;
            G += v * g_info[x];
        } 

        for (int x = 0; x < 7; x++) {
            cin >> v;
            S += v * s_info[x];
        }

        if (G > S) cout << "Battle " << i << ": Good triumphs over Evil\n";
        else if (G < S) cout << "Battle " << i << ": Evil eradicates all trace of Good\n";
        else cout << "Battle " << i << ": No victor on this battle field\n";
    }
}