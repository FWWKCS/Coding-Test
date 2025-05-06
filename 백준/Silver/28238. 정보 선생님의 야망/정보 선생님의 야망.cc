#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n; cin >> n;
    vector<vector<int>> table(n, vector<int>(5));
    for (auto &r : table) {
        for (auto &c : r) cin >> c;
    }

    int answer = -1;
    int x = -1, y = -1;
    
    for (int i = 0; i < 4; i++) {
        for (int j = i+1; j < 5; j++) {
            int total = 0;
            for (int k = 0; k < n; k++) {
                if (table[k][i] && table[k][j]) total++; 
            }

            if (answer < total) {
                answer = total; 
                x = i, y = j;
            }
        }
    }

    cout << answer << '\n';
    for (int i = 0; i < 5; i++) cout << (i == x || i == y ? 1 : 0) << ' ';
}