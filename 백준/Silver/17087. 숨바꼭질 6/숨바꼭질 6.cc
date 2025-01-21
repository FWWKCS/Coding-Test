#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int GCD(int div, int mod) {
    if (mod == 0) return div;

    return GCD(mod, div % mod); 
}

int diff[100'000];

int main() {
    FASTIO;

    int N, S; cin >> N >> S;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        diff[i] = abs(S-x);
    }

    if (N == 1) {
        cout << diff[0];
        return 0;
    }

    int answer = GCD(diff[0], diff[1]);
    for (int i = 2; i < N; i++) {
        answer = GCD(diff[i], answer);
    }

    cout << answer;
}