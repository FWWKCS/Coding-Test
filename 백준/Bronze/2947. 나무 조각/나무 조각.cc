#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    vector<int> piece;
    string line; 
    getline(cin, line);
    int x, tmp;

    istringstream is(line);
    while (is >> x) piece.push_back(x);

    vector<int> target = {1, 2, 3, 4, 5};
    while (!equal(piece.begin(), piece.end(), target.begin())) {
        for (int i = 0; i < 4; i++) {
            if (piece[i] > piece[i+1]) {
                tmp = piece[i];
                piece[i] = piece[i+1];
                piece[i+1] = tmp;
                
                for (auto x : piece) cout << x << ' ';
                cout << '\n';
            }
        }
    }
}