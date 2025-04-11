#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;
    char pict[n][m];
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) cin >> pict[r][c];
    }

    int answer = 0;
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < m; c++) {
            char x; cin >> x;
            if (pict[r][c] == x) answer++; 
        }
    }

    cout << answer;
}