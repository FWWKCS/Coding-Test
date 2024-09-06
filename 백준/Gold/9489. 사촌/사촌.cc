#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    while (true) {
        int n, k; cin >> n >> k;
        if (n == 0 && k == 0) return 0;

        vector<int> seq(n+1);
        for (int i = 1; i <= n; i++) {
            int x; cin >> x;
            seq[i] = x;
        }

        vector<int> ctop(n+1, -1);

        int idx = 1;
        for (int i = 2; i <= n; i++) {
            ctop[i] = idx;

            if (idx <= n && seq[i+1] > seq[i]+1) idx++;
        }

        int k_idx = -1;
        for (int i = 1; i <= n; i++) {
            if (seq[i] == k) k_idx = i; 
        }

        int myP_idx = ctop[ctop[k_idx]];

        int answer = 0;
        for (auto x : ctop) {
            if (ctop[x] == myP_idx && x != ctop[k_idx]) answer++;
        }

        cout << answer << '\n';       
    }
}