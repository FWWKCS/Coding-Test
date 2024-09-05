#include <iostream>
#include <vector>
#include <tuple>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void dfs(vector<vector<tuple<int, int>>> &tree, vector<bool> &visited, int current, int &target, int &total, int length) {
    visited[current] = true;

    for (auto x : tree[current]) {
        if (visited[get<0>(x)]) continue;

        if (total < length + get<1>(x)) {
            target = get<0>(x);
            total = length + get<1>(x);
        }

        dfs(tree, visited, get<0>(x), target, total, length + get<1>(x));
    }
}

int main() {
    FASTIO;

    int V; cin >> V;
    vector<vector<tuple<int, int>>> tree(V+1);
    for (int i = 1; i <= V; i++) {
        int r; cin >> r;
        while (true) {
            int u; cin >> u;
            if (u > 0) {
                int d; cin >> d;
                tree[r].push_back(make_tuple(u, d));
            }
            else break;
        }
    }

    int target;
    int total = 0;
    vector<bool> visited(V+1, false);
    dfs(tree, visited, 1, target, total, 0);

    for (int i = 0; i <= V; i++) visited[i] = false;
    dfs(tree, visited, target, target, total, 0);
    cout << total;
}