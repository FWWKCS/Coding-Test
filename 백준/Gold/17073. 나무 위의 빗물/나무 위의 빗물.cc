#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <queue>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void dfs(vector<vector<int>> &tree, vector<bool> &visited, int root, int &count) {
    visited[root] = true;

    bool reach = false;
    for (auto x : tree[root]) {
        if (visited[x]) continue;

        reach = true;
        dfs(tree, visited, x, count);
    }

    if (!reach) count++;
}   

int main() {
    FASTIO;

    int N;
    long double W; 
    cin >> N >> W;

    vector<vector<int>> tree(N+1);
    for (int i = 0; i < N-1; i++) {
        int U, V; cin >> U >> V;

        tree[U].push_back(V);
        tree[V].push_back(U);
    }

    vector<bool> visited(N+1, false);
    int count = 0;
    dfs(tree, visited, 1, count);
    cout << fixed << setprecision(10) << W/count;
}