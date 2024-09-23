#include <iostream>
#include <vector>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    set<int> ftf;
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    while (m--) {
        int a, b; cin >> a >> b;
        graph[a].push_back(b);
        graph[b].push_back(a);
    }

    // 1의 친구 탐색
    for (auto x : graph[1]) {
        ftf.insert(x);
        // x의 친구를 모두 탐색
        for (auto y : graph[x]) {
            if (y != 1) ftf.insert(y);    
        }
    }

    cout << ftf.size();
}