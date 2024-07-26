#include <iostream>
#include <vector>
#define MAX 2001
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> white(n+1, vector<int>(m+1, 0)), black(n+1, vector<int>(m+1, 0));
    for (int i = 1; i <= n; i++) {
        string tmp;
        cin >> tmp;
        for (int j = 1; j <= m; j++) {
            if (tmp[j-1] == 'W') { 
                // black판에서 r+c가 짝수인 곳이 W면 칠해야함
                if ((i+j) % 2 == 0) black[i][j] = 1;
                // white판에서 r+c가 홀수인 곳이 W면 칠해야함
                else white[i][j] = 1; 
            }
            else { // B
                // white판에서 r+c가 짝수인 곳이 B면 칠해야함
                if ((i+j) % 2 == 0) white[i][j] = 1;
                // black판에서 r+c가 홀수인 곳이 B면 칠해야함
                else black[i][j] = 1;
            }

            white[i][j] = white[i][j] + white[i-1][j] + white[i][j-1] - white[i-1][j-1];
            black[i][j] = black[i][j] + black[i-1][j] + black[i][j-1] - black[i-1][j-1];
        }
    }

    int answer = (int)1e9;
    for (int r = k; r <= n; r++) {
        for (int c = k; c <= m; c++) {
            int w = white[r][c] - white[r][c-k] - white[r-k][c] + white[r-k][c-k];
            int b = black[r][c] - black[r][c-k] - black[r-k][c] + black[r-k][c-k];
            answer = min(answer, min(w, b));
        }
    }

    cout << answer;
}