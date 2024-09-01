#include <iostream>
#include <vector>
#include <math.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int K;

void divide(vector<int> &btree, vector<vector<int>> &answer, int s, int e, int depth) {
    if (depth > K || s > e) return;

    int mid = (s+e) / 2;
    answer[depth].push_back(btree[mid]);

    divide(btree, answer, s, mid-1, depth+1);
    divide(btree, answer, mid+1, e, depth+1);
}

int main() {
    FASTIO;

    cin >> K;
    int T = (pow(2, K))-1;
    vector<int> btree;
    while (T--) {
        int v; cin >> v;
        btree.push_back(v);
    }

    vector<vector<int>> answer(K+1);
    divide(btree, answer, 0, btree.size()-1, 1);
    for (int l = 1; l <= K; l++) {
        for (auto v : answer[l]) cout << v << ' ';
        if (l != K) cout << '\n';
    }
}