#include <iostream>
#include <vector>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    vector<int> tree(N+1, 0);
    for (int i = 1; i <= N; i++) {
        int x; cin >> x;
        tree[i] = x;
    }

    sort(tree.begin()+1, tree.end(), greater<int>());

    long long day = 0;
    for (int i = 1; i <= N; i++) {
        day = max(day, (long long)(i + 1 + tree[i]));
    }

    cout << day;
}