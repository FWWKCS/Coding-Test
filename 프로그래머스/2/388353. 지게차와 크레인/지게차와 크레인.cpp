#include <string>
#include <vector>
#include <queue>
using namespace std;

int n, m;
vector<vector<char>> table;
vector<pair<int, int>> target;
int answer = 0;

int dr[4] = {-1, 1, 0, 0};
int dc[4] = {0, 0, -1, 1};

void check(int r, int c) {
    vector<vector<int>> visited(n, vector<int>(m, 0));
    queue<pair<int, int>> q;
    visited[r][c] = 1;
    q.push({r, c});
    
    while (!q.empty()) {
        int cR = q.front().first, cC = q.front().second;
        q.pop();
        
        if (cR == 0 || cR == n-1 || cC == 0 || cC == m-1) {
            target.push_back({r, c});
            return;
        }
        
        for (int i = 0; i < 4; i++) {
            int nR = cR + dr[i], nC = cC + dc[i];
            if (nR > -1 && nR < n && nC > -1 && nC < m && !visited[nR][nC] && table[nR][nC] == ' ') {
                q.push({nR, nC});
                visited[nR][nC] = 1;
            }
        }
    }
}

int solution(vector<string> storage, vector<string> requests) {
    n = storage.size();
    m = storage[0].size();
    
    table.resize(n, vector<char>(m));
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) table[r][c] = storage[r][c];
    }
    
    for (string rq : requests) {
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < m; c++) {
                if (rq[0] == storage[r][c]) {
                    if (rq.length() == 1) {
                        // 탐색
                        check(r, c);
                    }
                    else table[r][c] = ' ';
                }
            }
        }
        
        // 뺄 수 있는 영역을 제거
        while (!target.empty()) {
            int tr = target.back().first, tc = target.back().second;
            target.pop_back();
            table[tr][tc] = ' ';
        }
    }
    
    
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            if (table[r][c] != ' ') answer++;
        }
    }
    
    
    return answer;
}