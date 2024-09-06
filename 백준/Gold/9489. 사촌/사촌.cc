#include <iostream>
#include <vector>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    while (true) {
        int n, k; cin >> n >> k;
        if (n == 0 && k == 0) return 0;

        vector<int> seq(n);
        // map<int, vector<int>> ptoc;
        // map<int, int> ctop;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            seq[i] = x;
        }

        int MAX = seq[n-1];
        vector<vector<int>> ptoc(MAX+1);
        vector<int> ctop(MAX+1);

        int idx = 1;
        for (int i = 0; i < n; i++) {
            int root = seq[i];
            while (idx < n) {
                int value = seq[idx];
                ptoc[root].push_back(value);
                ctop[value] = root;

                if (seq[idx+1] > value+1) {
                    idx++;
                    break;
                }
                idx++;
            }
        }

        int myP = ctop[k];
        int myGP = ctop[myP];
        int count = 0;
        for (auto x : ptoc[myGP]) {
            if (x == 0 || x == myP) continue;

            count += ptoc[x].size();
        }

        cout << count << '\n';
    }
}