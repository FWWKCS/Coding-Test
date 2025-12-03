#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, M; cin >> N >> M;
    vector<vector<char>> table(N, vector<char>(M));

    for (auto &r : table) {
        for (auto &c : r) cin >> c;
    }

    int answer = -1;
    for (int i = 0; i < M; i++) {
        bool found = true;
        for (int j = 0; j < N; j++) {
            if (table[j][i] == 'O') {
                found = false;
                break;
            }
        }

        if (found) {
            answer = i+1;
            break;
        }
    }

    if (answer > 0) cout << answer;
    else cout << "ESCAPE FAILED";
}