#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

int main() {
    double N, M, K; cin >> N >> M >> K;

    vector<vector<double>> comb(9, vector<double>(9, 0));
    for (int i = 0; i < 9; i++) {
        comb[i][0] = 1;
        comb[i][i] = 1;
    }

    for (int r = 2; r <= 8; r++) {
        for (int c = 1; c < r; c++) {
            comb[r][c] = comb[r-1][c-1] + comb[r-1][c];
        }
    }
 

    double total = comb[N][M] * comb[N][M];
    double p = 0;
    for (int i = 0; i < K; i++) {
        p += comb[N][M] * comb[M][i] * comb[N-M][M-i];
    }

    cout << fixed << setprecision(9);

    cout << 1 - (p / total);
    return 0;
}