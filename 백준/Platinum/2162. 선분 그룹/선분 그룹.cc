#include <iostream>
#include <vector>
#include <map>
#define x first
#define y second
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

vector<pair<pair<int, int>, pair<int, int>>> lines = {{{-1e9, -1e9}, {1e9, 1e9}}}; 
vector<int> parent;

pair<int, int> A, B, C, D;

int find_root(int x) {
    if (x == parent[x]) return x;
    return parent[x] = find_root(parent[x]);
}

void join(int i, int j) {
    i = find_root(i);
    j = find_root(j);

    if (i != j) parent[i] = j;
} 

int CCW(pair<int, int> U, pair<int, int> V, pair<int, int> W) {
    long long result = (V.x-U.x)*(W.y-U.y)-(V.y-U.y)*(W.x-U.x);
    
    if (result < 0) return -1;
    else if (result > 0) return 1;
    else return 0;
}

int main() {
    FASTIO;
    
    int N; cin >> N;
    parent.resize(N+1);
    for (int i = 0; i <= N; i++) parent[i] = i;

    for (int i = 1; i <= N; i++) {
        int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
        lines.push_back({{x1, y1}, {x2, y2}});
    }

    for (int i = 1; i <= N; i++) {
        for (int j = i+1; j <= N; j++) {
            A = lines[i].x, B = lines[i].y;
            if (A > B) swap(A, B);
            C = lines[j].x, D = lines[j].y;
            if (C > D) swap(C, D);

            int c1 = CCW(A, B, C);
            int c2 = CCW(A, B, D);
            int c3 = CCW(C, D, A);
            int c4 = CCW(C, D, B);

            if (c1*c2 == 0 && c3*c4 == 0) {
                if (B < C || D < A) continue;
                else join(i, j);
            }
            else if (c1*c2 <= 0 && c3*c4 <= 0)
                join(i, j);
        }
    }

    for (int i = 1; i <= N; i++) find_root(i);

    map<int, int> g;
    int maxTotal = 0;
    for (int i = 1; i <= N; i++) {
        int r = parent[i];
        g[r]++;
        maxTotal = max(maxTotal, g[r]);
    }

    cout << g.size() << '\n' << maxTotal;
}