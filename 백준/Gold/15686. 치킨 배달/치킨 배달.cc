#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N, M;
vector<pair<int, int>> H, S;
int answer = 1e9;

int chickenDist(pair<int, int>& p, pair<int, int>& q) {
    return abs(p.first-q.first) + abs(p.second-q.second);
}

void recursion(int depth, vector<pair<int, int>> selected, int last) {
    if (depth == M && selected.empty()) return;

    if (depth == M) {
        int total = 0;
        // 길이 계산
        for (auto p : H) {
            int d = 1e9;
            for (auto q : selected) {
                d = min(d, chickenDist(p, q));
            }

            total += d;
        }

        answer = min(answer, total);
        return;
    }

    for (int i = last+1; i < S.size(); i++) {
        // select
        selected.push_back(S[i]);
        recursion(depth+1, selected, i);
        selected.pop_back();
    }
}


int main() {
    FASTIO;

    cin >> N >> M;
    for (int i = 1; i <= N; i++) {
        for (int j = 1; j <= N; j++) {
            int x; cin >> x;
            if (x == 1) H.push_back({i, j});
            else if (x == 2) S.push_back({i, j});
        }
    }

    vector<pair<int, int>> selected;
    recursion(0, selected, -1);

    cout << answer;
}