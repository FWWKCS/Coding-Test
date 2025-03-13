#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

vector<vector<int>> seg = {
    {1, 1, 1, 0, 1, 1, 1},
    {0, 0, 1, 0, 0, 1, 0},
    {1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 0, 1, 0},
    {1, 1, 0, 1, 0, 1, 1},
    {1, 1, 0, 1, 1, 1, 1},
    {1, 0, 1, 0, 0, 1, 0},
    {1, 1, 1, 1, 1, 1, 1},
    {1, 1, 1, 1, 0, 1, 1}
};

vector<vector<int>> info(10, vector<int>(10, 0));

int main() {
    int N, K, P, X; cin >> N >> K >> P >> X;

    for (int r = 0; r < 9; r++) {
        for (int c = r+1; c < 10; c++) {
            for (int k = 0; k < 7; k++) {
                info[r][c] += abs(seg[r][k] - seg[c][k]);
            }

            info[c][r] = info[r][c];
        }
    }

    int answer = 0;
    for (int v = 1; v <= N; v++) {
        if (v == X) continue;

        int total = 0;
        for (int t = 0; t < K; t++) {
            if (t == 0) total += info[X % 10][v % 10];
            else {
                total += info[(X % (int)pow(10, t+1)) / pow(10,t)][(v % (int)(pow(10, t+1))) / pow(10,t)];
            }
        }

        if (total <= P) answer++;
    }

    cout << answer;
}