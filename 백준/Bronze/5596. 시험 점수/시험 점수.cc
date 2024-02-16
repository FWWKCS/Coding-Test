#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> Min(4, 0);
    vector<int> Man(4, 0);
    int i;
    for (i = 0; i < 4; i++) cin >> Min[i];
    for (i = 0; i < 4; i++) cin >> Man[i];
    
    int S = accumulate(Min.begin(), Min.end(), 0);
    int T = accumulate(Man.begin(), Man.end(), 0);

    if (S >= T) cout << S;
    else cout << T;
}