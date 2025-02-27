#include <iostream>
#include <set>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, K;

int main() {
    FASTIO;

    cin >> N >> K;
    vector<int> dir(N);
    for (auto &x : dir) cin >> x;

    set<int> visited;
    int answer = 1;
    int cur = 0, next = -1;
    while (true) {
        next = dir[cur];
        if (next == K) break;

        if (visited.find(next) != visited.end()) {
            cout << -1;
            return 0;
        }
        
        visited.insert(next);
        cur = next;
        answer++;
    }

    cout << answer;
}