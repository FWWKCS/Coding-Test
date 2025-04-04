#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

int N, M, C;
vector<set<int>> g;
set<int> visited;

bool isCycle = false;

void check(int cur) {
    for (int next : g[cur]) {
        if (isCycle) return;

        if (visited.find(next) != visited.end()) {
            isCycle = true;
            return;
        }
        else {
            visited.insert(next);
            check(next);
            visited.erase(next);
        }
    }
}

int main() {
    cin >> N;
    g.resize(N+1);

    for (int i = 1; i < N; i++) {
        cin >> M;
        while (M--) {
            cin >> C;
            g[i].insert(C);
        }
    }

    check(1);
    cout << (isCycle ? "CYCLE" : "NO CYCLE");
}