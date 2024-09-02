#include <iostream>
#include <unordered_map>
#include <unordered_set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

bool check(unordered_map<int, int> &visited, unordered_set<int> &nodes) {
    // 부모가 2이상인 노드 체크
    for (auto x : visited) if (x.second >= 2) return false;
    

    // 부모 노드가 없는 단 하나의 노드를 탐색
    int root = -1;

    // for (auto x : nodes) cout << x << ' ';
    // cout << '\n';

    for (auto x : nodes) {
        if (visited.find(x) == visited.end()) {
            if (root == -1) root = x;
            else return false;
        }
    }

    if (root == -1) return false;

    return true;
}

int main() {
    FASTIO;

    int T = 1;
    while (true) {
        unordered_map<int, int> visited;
        unordered_set<int> nodes;
        bool invalid = false;
        while (true) {
            // 정점 입력
            int u, v; cin >> u >> v;
            if (u == 0 && v == 0) break;
            if (u == -1 && v == -1) return 0;

            if (u == v) invalid = true;

            if (visited.find(v) == visited.end()) visited[v] = 1;
            else visited[v]++;

            nodes.insert(u);
            nodes.insert(v);
        }
        
        // 노드가 없어도 Tree   
        bool isTree = false;
        if (nodes.empty()) isTree = true;
        else if (!invalid && check(visited, nodes)) isTree = true;
       

        if (isTree) cout << "Case " << T << " is a tree.\n";
        else cout << "Case " << T << " is not a tree.\n";

        cin.ignore();
        string value;
        getline(cin, value);

        if (value == "-1 -1") break;

        T++;
    }
}