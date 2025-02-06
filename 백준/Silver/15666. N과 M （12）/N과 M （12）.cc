#include <iostream>
#include <vector>
#include <set>
using namespace std;

int N, M;
vector<int> seq;

void recursion(int depth, vector<int> s) {
    if (depth == M) {
        for (int x : s) cout << x << ' ';
        cout << '\n';
        return;
    }

    for (int x : seq) {
        if (s.size() > 0 && s.back() > x) continue;
        s.push_back(x);
        recursion(depth+1, s);
        s.pop_back();
    }
}

int main() {
    cin >> N >> M;
    set<int> p;
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        p.insert(x);
    }

    for (auto x : p) seq.push_back(x);

    vector<int> s;
    recursion(0, s);
}