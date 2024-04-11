#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N, M; cin >> N >> M;
    vector<vector<int>> picture(101, vector<int>(101, 0));

    int x1, y1, x2, y2;
    for (int i = 0; i < N; i++) {
        cin >> x1 >> y1 >> x2 >> y2;
        for (int r = y1; r <= y2; r++) {
            for (int c = x1; c <= x2; c++) {
                picture[r][c]++;
            }
        }
    }

    int count = 0;
    for (int r = 1; r <= 100; r++) {
        for (int c = 1; c <= 100; c++) {
            if (picture[r][c] > M) count++;
        }
    }

    cout << count;

}