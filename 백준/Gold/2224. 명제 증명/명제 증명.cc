#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <set>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int total = 0;

void bfs(map<char, vector<char>> &graph, map<char, set<char>> &rel, char start) {
    set<char> visited = {start};

    queue<char> q;
    q.push(start);

    while (!q.empty()) {
        char top = q.front();
        q.pop();

        for (auto v : graph[top]) {
            if (visited.find(v) != visited.end()) continue;

            total++;
            visited.insert(v);
            rel[start].insert(v);
            q.push(v);
        }
    }
}

int main() {
    FASTIO;

    int X; cin >> X;
    cin.ignore();
    map<char, vector<char>> graph;
    map<char, set<char>> rel;
    while (X--) {
        string line; 
        getline(cin, line);
        char P = line[0], Q = line[5];

        if (graph.find(P) != graph.end()) graph[P].push_back(Q);
        else {
            graph[P] = {Q};
            rel[P] = {};
        }
    }

    for (auto v : graph) {
        bfs(graph, rel, v.first);
    }

    cout << total << '\n';
    for (auto v : rel) {
        for (auto x : v.second) {
            cout << v.first << " => " << x << '\n';
        }
    }
}