#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, i, k; cin >> N;
    int count = 0;
    set<int> S;
    for (i = 0; i < N; i++) {
        cin >> k;
        if (S.find(k) == S.end()) S.insert(k);
        else count++;   
    }
    cout << count;
}