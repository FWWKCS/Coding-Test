#include <iostream>
#include <vector>
using namespace std;

int main() {
    int R, C, W; cin >> R >> C >> W;

    vector<vector<long long>> pascal(R+W, vector<long long>(R+W, 0));

    pascal[1][1] = 1;
    for (int r = 2; r < R+W; r++) {
        for (int c = 1; c <= r; c++) {
            pascal[r][c] = pascal[r-1][c-1] + pascal[r-1][c];
        }
    }

    long long answer = 0;
    for (int r = R; r < R+W; r++) {
        for (int k = 0; k <= r-R; k++) {
            answer += pascal[r][C+k];
        }
    }

    cout << answer;
}