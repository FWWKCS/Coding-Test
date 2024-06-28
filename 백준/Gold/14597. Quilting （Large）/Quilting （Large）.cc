#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
    int H, W; cin >> H >> W;

    vector<vector<int>> A(H, vector<int>(W, 0)), B(H, vector<int>(W, 0));
    int x;

   
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cin >> x;
            A[r][c] = x;
        }
    }

    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            cin >> x;
            B[r][c] = x;
        }
    }
    

    vector<vector<int>> dp(H, vector<int>(W, 300*300));
    for (int r = 0; r < H; r++) {
        for (int c = 0; c < W; c++) {
            dp[r][c] = (A[r][c]-B[r][c])*(A[r][c]-B[r][c]);
        }
    }

    if (W == 1) {
        for (int r = 1; r < H; r++) {
            dp[r][0] += dp[r-1][0];
        }
    }
    else {
        for (int r = 1; r < H; r++) {
            for (int c = 0; c < W; c++) {
                if (c == 0) {
                    dp[r][c] += min(dp[r-1][c], dp[r-1][c+1]);
                }
                else if (c == W-1){
                    dp[r][c] += min(dp[r-1][c-1], dp[r-1][c]);
                }
                else {
                    dp[r][c] += min(min(dp[r-1][c-1], dp[r-1][c]), dp[r-1][c+1]);
                }
            }
        }
    }

    cout << *min_element(dp[H-1].begin(), dp[H-1].end());
}