#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int M, N, K, W; 
vector<vector<int>> A;

int find_median(int r, int c) {
    vector<int> tmp;
    for (int i = r; i < r+W; i++) {
        for (int j = c; j < c+W; j++) tmp.push_back(A[i][j]);
    }
    sort(tmp.begin(), tmp.end());

    return tmp[(W*W)/2];
}

int main() {
    cin >> M >> N >> K >> W;
    A.resize(M, vector<int>(N));
    for (auto &r : A) {
        for (auto &c : r) cin >> c;
    }

    vector<vector<int>> B(M-W+1, vector<int>(N-W+1));

    for (int r = 0; r < M-W+1; r++) {
        for (int c = 0; c < N-W+1; c++) {
            B[r][c] = find_median(r, c);
        }
    }

    for (auto r : B) {
        for (auto c : r) cout << c << ' ';
        cout << '\n';
    }
}