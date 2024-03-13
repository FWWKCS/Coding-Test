#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;

    for (int i = 0; i < T; i++) {
        vector<int> vote(1, 0);
        int n; cin >> n;
        int k, R, value, total = 0;

        bool elected = true;

        for (int j = 0; j < n; j++) {
            cin >> k;
            total += k;
            vote.push_back(k);
        }

        // find max value
        value = *max_element(vote.begin(), vote.end());
        R = max_element(vote.begin(), vote.end()) - vote.begin();

        // check same max value
        for (int i = 1; i < vote.size(); i++) {
            if (i == R) continue;
            else if (vote[i] == value) {
                elected = false;
                break;
            }
        }

        // decision election state
        if (elected) {
            if (value > total / 2) cout << "majority winner " << R << '\n';
            else cout << "minority winner " << R << '\n';
        }
        else cout << "no winner\n";
    }   
}