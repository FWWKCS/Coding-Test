#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, x;
    vector<int> queue;
    while (true) {
        cin >> N;
        if (N == 0) break;

        for (int i = 0; i < N; i++) {
            cin >> x;
            if (queue.empty()) queue.push_back(x);
            else if (queue[queue.size()-1] != x) queue.push_back(x);
        }

        for (auto x : queue) cout << x << ' ';
        cout << "$\n";

        queue.clear();
    }
}