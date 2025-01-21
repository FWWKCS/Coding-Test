#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int GCD(int div, int mod) {
    if (mod == 0) return div;

    return GCD(mod, div % mod); 
}

int main() {
    FASTIO;

    int N, S; cin >> N >> S;
    vector<int> diff;

    while (N--) {
        int x; cin >> x;
        diff.push_back(abs(S-x));
    }

    if (diff.size() == 1) {
        cout << diff[0];
        return 0;
    }

    int answer = GCD(diff[0], diff[1]);
    for (int i = 2; i < diff.size(); i++) {
        answer = GCD(diff[i], answer);
    }

    cout << answer;
}