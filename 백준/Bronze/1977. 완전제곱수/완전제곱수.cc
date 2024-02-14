#include <bits/stdc++.h>

using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);

    vector<int> v(101);
    for (int i = 0; i <= 100; i++) v[i] = i*i;

    int M, N, s, e; 
    int sum = 0; 
    int min = 100000;

    cin >> M;
    cin >> N;
    s = (int)sqrt(M);
    e = (int)sqrt(N);

    for (int i = s; i <= e; i++) {
        if (M <= v[i] && v[i] <= N) {
            sum += v[i];
            if (v[i] < min) min = v[i];
        }
    } 

    if (min == 100000) {
        cout << -1;
    } else {
        cout << sum << '\n' << min;
    }
}