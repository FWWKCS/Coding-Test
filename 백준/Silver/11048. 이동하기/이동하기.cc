#include <iostream>
#include <vector>
#include <deque>
#include <tuple>
using namespace std;

int N, M;


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> N >> M;
    vector<vector<int>> table(1, vector<int>(M+1, 0));
    for (int i = 0; i < N; i++) {
        vector<int> line(1, 0);
        int x;
        for (int j = 0; j < M; j++) {
            cin >> x;
            line.emplace_back(x);
        }
        table.emplace_back(line);
    }

    vector<vector<int>> count(N+1, vector<int>(M+1, 0));
    for (int i = 1; i <= M; i++) count[1][i] = count[1][i-1] + table[1][i];
    for (int i = 1; i <= N; i++) count[i][1] = count[i-1][1] + table[i][1];

    for (int r = 2; r <= N; r++) {
        for (int c = 2; c <= M; c++) {
            count[r][c] = max(max(count[r-1][c], count[r][c-1]), count[r-1][c-1]) + table[r][c];
        }
    }

    cout << count[N][M];
    
}