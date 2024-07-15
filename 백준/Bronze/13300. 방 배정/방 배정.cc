#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, K; cin >> N >> K;
    vector<vector<int>> student(2, vector<int>(7, 0));
    for (int i = 0; i < N; i++) {
        int S, Y; cin >> S >> Y;
        student[S][Y]++;
    }

    int count = 0;
    for (int r = 0; r < 2; r++) {
        for (int c = 1; c < 7; c++) {
            if (student[r][c] % K != 0) count += (student[r][c] / K) + 1;
            else count += student[r][c] / K;
        }
    }
    cout << count;
}