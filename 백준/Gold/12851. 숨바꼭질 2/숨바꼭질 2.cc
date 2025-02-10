#include <iostream>
#include <queue>
#include <vector>
#define MAX 100'000
using namespace std;

int N, K;
vector<int> board(MAX + 1, 1e9); // 최소 시간 저장
vector<int> total(MAX + 1, 0);   // 경우의 수 저장

void bfs() {
    queue<pair<int, int>> q; // 위치, 시간
    q.push({N, 0});
    board[N] = 0;
    total[N] = 1;

    while (!q.empty()) {
        int X = q.front().first;
        int T = q.front().second;
        q.pop();

        // 다음 위치 탐색
        vector<int> next_positions = {X - 1, X + 1, X * 2};
        for (int next : next_positions) {
            if (next < 0 || next > MAX) continue;

            // 더 짧은 경로 발견
            if (board[next] > T + 1) {
                board[next] = T + 1;
                total[next] = total[X]; // 경우의 수 갱신
                q.push({next, T + 1});
            }
            // 동일한 최단 거리 경로 발견
            else if (board[next] == T + 1) {
                total[next] += total[X]; // 경우의 수 누적
            }
        }
    }
}

int main() {
    cin >> N >> K;

    bfs();
    cout << board[K] << '\n' << total[K] << '\n';

    return 0;
}