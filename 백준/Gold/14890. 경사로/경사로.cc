#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int N, L;
vector<vector<int>> table;

int row(int r) {
    vector<int> dir(N+1, 0);
    int c = 2;
    for (; c <= N; c++) {
        if (table[r][c-1] > table[r][c]) {
            // down

            // 높이차가 1인지 검사
            if (table[r][c-1]-table[r][c] > 1) return 0;

            if (L > 1) {
                // c 부터 c-1+L 까지 높이 검사
                for (int i = c+1; i <= c-1+L; i++) {
                    if (i > N) return 0;
                    if (dir[i-1] != 0) return 0;
                    if (table[r][i-1] != table[r][i]) return 0;
                }
                for (int i = c; i <= c-1+L; i++) dir[i] = -1;
            }
            else {
                // c 검사
                if (dir[c] != 0) return 0;
                dir[c] = -1;
            }


        }
        else if (table[r][c-1] < table[r][c]) {
            // up

            // 높이차가 1인지 검사
            if (table[r][c] - table[r][c-1] > 1) return 0;

            if (L > 1) {
                // c-L 부터 c-1까지 높이 검사
                for (int i = c-L+1; i <= c-1; i++) {
                    if (i <= 0) return 0;
                    if (dir[i-1] != 0) return 0;
                    if (table[r][i-1] != table[r][i]) return 0;
                }
    
                for (int i = c-L; i <= c-1; i++) dir[i] = 1;
            }
            else {
                // c 검사
                if (dir[c-1] != 0) return 0;
                dir[c-1] = 1;
            }
        }
    }

    // cout << "row " << r << '\n'; 
    // for (auto d : dir) cout << d << ' ';
    // cout << "\n\n";
    return 1;
}

int col(int c) {
    vector<int> dir(N+1, 0);
    int r = 2;
    for (; r <= N; r++) {
        if (table[r-1][c] > table[r][c]) {
            // down

            // 높이차가 1인지 검사
            if (table[r-1][c]-table[r][c] > 1) return 0;

            if (L > 1) {
                // r 부터 r-1+L 까지 높이 검사
                for (int i = r+1; i <= r-1+L; i++) {
                    if (i > N) return 0;
                    if (dir[i-1] != 0) return 0;
                    if (table[i-1][c] != table[i][c]) return 0;
                }
    
                for (int i = r; i <= r-1+L; i++) dir[i] = -1;
            }
            else {
                if (dir[r] != 0) return 0;
                dir[r] = -1;
            }
        }
        else if (table[r-1][c] < table[r][c]) {
            // up

            // 높이차가 1인지 검사
            if (table[r][c] - table[r-1][c] > 1) return 0;
            
            if (L > 1) {
                // r-L 부터 r-1까지 높이 검사
                for (int i = r-L+1; i <= r-1; i++) {
                    if (i <= 0) return 0;
                    if (dir[i-1] != 0) return 0;
                    if (table[i-1][c] != table[i][c]) return 0;
                }
    
                for (int i = r-L; i <= r-1; i++) dir[i] = 1;
            }
            else {
                if (dir[r-1] != 0) return 0;
                dir[r-1] = 1;
            }
        }
    }

    // cout << "col " << c << '\n';
    // for (auto d : dir) cout << d << ' ';
    // cout << "\n\n";
    return 1;
}


int main() {
    FASTIO;

    cin >> N >> L;

    table.resize(N+1, vector<int>(N+1));
    for (int r = 1; r <= N; r++) {
        for (int c = 1; c <= N; c++) cin >> table[r][c];
    } 

    int answer = 0;

    for (int i = 1; i <= N; i++) answer += row(i);
    for (int i = 1; i <= N; i++) answer += col(i);

    cout << answer;
}