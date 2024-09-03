#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    vector<int> count(N+1, 0);
    for (int i = 0; i < N-1; i++) {
        int a, b; cin >> a >> b;
        
        count[a]++;
        count[b]++;
    }

    int q; cin >> q;
    while (q--) {
        int t, k; cin >> t >> k;
        if (t == 1) {
            if (count[k] > 1) cout << "yes\n";
            else cout << "no\n";
        }
        else cout << "yes\n";
    }
}