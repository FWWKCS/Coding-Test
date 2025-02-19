#include <iostream>
#include <vector>
#include <set>
#include <algorithm>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

set<int> s;
vector<vector<int>> info(101, vector<int>(2, 0));

bool customSort(vector<int>& a, vector<int>& b) {
    if (a[1] != b[1]) return a[1] < b[1];
    return a[2] < b[2];
}

int main() {    
    FASTIO;

    int N, M; cin >> N >> M;

    for (int i = 1; i <= M; i++) {
        int k; cin >> k;
        // 이미 있는지
        if (s.find(k) != s.end()) info[k][0]++;

        // 없는데 넣을 공간이 있으면
        else if (s.size() < N) {
            s.insert(k);
            info[k][0] = 1;
            info[k][1] = i;
        }

        // 넣을 공간이 없으면
        else {
            vector<vector<int>> target;
            for (auto v : s) target.push_back({v, info[v][0], info[v][1]});

            sort(target.begin(), target.end(), customSort);

            int t = target[0][0];
            s.erase(t);
            info[t][0] = 0;

            // 새로 추가
            s.insert(k);
            info[k][0] = 1;
            info[k][1] = i;
        } 
    }

    for (auto v : s) cout << v << ' ';
}