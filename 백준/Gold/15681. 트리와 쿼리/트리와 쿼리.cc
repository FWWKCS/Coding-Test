#include <iostream>
#include <vector>
#include <map>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, R, Q;
map<int, vector<int>> graph;
vector<vector<int>> child;
vector<int> subNodes;

void makeTree(int cur, int parent) {
    for (int next : graph[cur]) {
        if (next == parent) continue;
        child[cur].push_back(next);
        makeTree(next, cur);
    }
}

int countSubNodes(int cur) {
    for (int next : child[cur]) {
        subNodes[cur] += countSubNodes(next);
    }
    return subNodes[cur];
}

int main() {
    FASTIO;

    cin >> N >> R >> Q;
    child.resize(N+1);
    subNodes.resize(N+1, 1);
    N--;
    while (N--) {
        int U, V; cin >> U >> V;
        graph[U].push_back(V);
        graph[V].push_back(U);
    }

    makeTree(R, -1);
    countSubNodes(R);

    while (Q--) {
        int x; cin >> x;
        cout << subNodes[x] << '\n';
    }
}