#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int N;

int solve(string bomb[], int r, int c) {
    // UL, U, UR, L, R, DL, D, DR
    int dy[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    int dx[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

    int count = 0;
    for (int i = 0; i < 8; i++) {
        int dr = r + dy[i];
        int dc = c + dx[i];

        if (-1 < dr && dr < N && -1 < dc && dc < N && bomb[dr][dc] == '*') count++;
    }

    return count;
}

bool check(string bomb[], string target[]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (bomb[i][j] == '*' && target[i][j] == 'x') return true;
        }
    }

    return false;
}


int main() {
    FASTIO;

    cin >> N;
    string bomb[N];
    string target[N];


    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        bomb[i] = input;
    }

    for (int i = 0; i < N; i++) {
        string input; cin >> input;
        target[i] = input;
    }

    bool bomb_opened = check(bomb, target);

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (bomb_opened && bomb[i][j] == '*') cout << '*'; 

            else if (target[i][j] == 'x') {
                cout << solve(bomb, i, j);
            }
            else cout << target[i][j];
        }
        cout << '\n';
    }
}