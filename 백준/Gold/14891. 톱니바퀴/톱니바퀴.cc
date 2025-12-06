#include <iostream>
#include <vector>
#include <deque>
#include <cmath>
using namespace std;

vector<deque<char>> v;
// w1[2] <-> w2[6]
// w2[2] <-> w3[6]
// w3[2] <-> w4[6]
// N:0, S:1

void rotate(vector<int> r) {
    for (int i = 0; i < 4; i++) {
        if (r[i] == -1) { // 반시계
            char f = v[i].front();
            v[i].pop_front();
            v[i].push_back(f);
        }
        else if (r[i] == 1) { // 시계
            char b = v[i].back();
            v[i].pop_back();
            v[i].push_front(b);
        }

        // for (auto x : v[i]) cout << x;
        // cout << '\n';
    }
}

void update(int n, int d) {
    // d = 1: 시계
    // d = -1: 반시계

    vector<int> r(4, 0);
    r[n] = d;

    // left
    for (int x = n-1; x >= 0; x--) {
        if (v[x][2] != v[x+1][6]) {
            r[x] = -(r[x+1]);
        }
        else break;
    }

    // right
    for (int x = n+1; x < 4; x++) {
        if (v[x-1][2] != v[x][6]) {
            r[x] = -(r[x-1]);
        }
        else break;
    }

    // cout << '\n';
    // for (auto i : r) cout << i << ' ';
    // cout << '\n';

    rotate(r);
}

int main() {
    for (int i = 0; i < 4; i++) {
        deque<char> w;
        v.push_back(w);
    }

    string s; cin >> s;
    for (char c : s) v[0].push_back(c);
    cin >> s;
    for (char c : s) v[1].push_back(c);
    cin >> s;
    for (char c : s) v[2].push_back(c);
    cin >> s;
    for (char c : s) v[3].push_back(c);
    
    int K; cin >> K;
    while (K--) {
        int n, d; cin >> n >> d;
        update(n-1, d);
    }

    int answer = 0;
    for (int i = 0; i < 4; i++) {
        answer += (v[i][0]-'0') * pow(2, i);
    }
    cout << answer;
}