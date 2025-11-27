#include <iostream>
#include <vector>
using namespace std;

int main() {
    string S; cin >> S;
    int N = S.length(), R = 1, C; 

    for (C = N; C > 0; C--) {
        if (N % C == 0 && N / C <= C) {
            R = max(R, N/C);
        }
    }

    C = N/R;

    vector<vector<char>> T(C, vector<char>(R));
    for (int i = 0; i < N; i++) {
        T[i/R][i%R] = S[i];
    }

    for (int c = 0; c < R; c++) {
        for (int r = 0; r < C; r++) cout << T[r][c];
    }
}