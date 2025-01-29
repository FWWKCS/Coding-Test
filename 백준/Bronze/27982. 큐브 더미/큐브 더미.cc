#include <iostream>
#include <vector>
#include <tuple>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    int answer = 0;
    if (M > 6) {
        vector<vector<vector<int>>> space(N+2, vector<vector<int>>(N+2, vector<int>(N+2, 0)));

        vector<tuple<int, int, int>> list;
        for (int x = 0; x < M; x++) {
            int i, j, k; cin >> i >> j >> k;
            space[i][j][k] = 1;
            list.push_back(make_tuple(i,j,k));
        }

        for (auto l : list) {
            int i = get<0>(l), j = get<1>(l), k = get<2>(l);
            
            if (space[i+1][j][k] && space[i-1][j][k] 
            && space[i][j+1][k] && space[i][j-1][k] 
            && space[i][j][k+1] && space[i][j][k-1]) answer++;
        }
    }

    cout << answer;
}