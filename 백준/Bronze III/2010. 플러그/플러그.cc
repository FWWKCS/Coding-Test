#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int N; cin >> N;
    int k, total = 0;
    for (int i = 0; i < N; i++) {
        cin >> k; 
        total += k;
    } 

    cout << total - (N-1);
}