#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> info(1, vector<int>(M, 0));
    for (int i = 0; i < N; i++) {
        vector<int> cards;
        int x;
        for (int j = 0; j < M; j++) {
            cin >> x;
            cards.push_back(x);
        }
        sort(cards.begin(), cards.end());
        info.push_back(cards);
    }

    vector<int> score(N+1, 0);

    for (int k = 0; k < M; k++) {
        int maxValue = 0;
        for (int r = 1; r <= N; r++) {
            maxValue = max(maxValue, info[r][info[r].size()-1]);
        }

        for (int r = 1; r <= N; r++) {
            if (info[r][info[r].size()-1] == maxValue) score[r]++;
            info[r].pop_back();
        }
    }

    int maxScore = 0;
    for (auto s : score) maxScore = max(maxScore, s);
    for (int i = 1; i <= N; i++) {
        if (score[i] == maxScore) cout << i << ' ';
    }
}