#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> parent;

int find_root(int x) {
    if (x == parent[x]) return x;

    return parent[x] = find_root(parent[x]);
}

void join(int a, int b) {
    a = find_root(a);
    b = find_root(b);

    if (a != b) parent[a] = b;
}

int main() {
    FASTIO;

    int n, m; cin >> n >> m;
    parent.resize(n+1);
    for (int i = 0; i <= n; i++) parent[i] = i;
    while (m--) {
        int mode, a, b; cin >> mode >> a >> b;
        if (mode == 0) {
            join(a, b);
        }
        else {
            cout << (find_root(a) == find_root(b) ? "YES\n" : "NO\n");
        }
    }
}