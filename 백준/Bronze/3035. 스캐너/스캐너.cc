#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int R, C, ZR, ZC;
    cin >> R >> C >> ZR >> ZC;

    vector<string> newspaper;
    string input;
    for (int i = 0; i < R; i++) {
        cin >> input;
        newspaper.push_back(input);
    }

    for (int r = 0; r < R; r++) {
        for (int v = 0; v < ZR; v++) {
            for (int c = 0; c < C; c++) {
                for (int x = 0; x < ZC; x++) cout << newspaper[r][c];
            }
            cout << '\n';
        }
    }
}