#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string word = "quack";

int main() {
    FASTIO;
    
    string s; cin >> s;
    int len = s.size();
    if (len % 5 != 0) {
        cout << -1;
        return 0;
    }

    int maxD = len/5;
    vector<vector<char>> table(maxD, vector<char>(len, ' '));
    vector<int> next(maxD, 0);

    int answer = 0;
    for (int c = 0; c < len; c++) {
        char cur = s[c];
        bool found = false;
        for (int r = 0; r < maxD; r++) {
            if (cur == word[next[r]]) {
                answer = max(answer, r+1);
                found = true;
                table[r][c] = cur;
                next[r] = (next[r] + 1) % 5;
                break;
            }
        }

        if (!found) {
            cout << -1;
            return 0;
        }
    }

    cout << answer;
    return 0;
}