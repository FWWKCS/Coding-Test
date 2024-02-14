#include <bits/stdc++.h>
using namespace std;

int main(void) {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.precision(2);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int N = 0; cin >> N;
        int total = 0;
        float sum = 0;
        for (int j = 0; j < N; j++) {
            int value; cin >> value;
            total += value;
            float score; cin >> score;
            sum += (float)value * score;
        }
        cout << fixed << setprecision(1) << total << ' ' << sum / (float)total << '\n';
    }
}