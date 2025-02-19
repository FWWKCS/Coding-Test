#include <iostream>
#include <vector>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int T; 

bool check(vector<int>& v) {
    int s = 0, e = v.size()-1;

    while (s <= e) {
        if (v[s] != v[e]) return false;
        s++; e--;
    }
    return true;
}

void makePNS(vector<int>& v, int N, int B) {
    while (N > 0) {
        v.push_back(N % B);
        N /= B;
    }
}

int main() {
    FASTIO;

    cin >> T;

    while (T--) {
        bool sym = false;
        int N; cin >> N;
        vector<int> v;
        for (int i = 2; i <= 64; i++) {
            makePNS(v, N, i);
            if (check(v)) {
                sym = true;
                break;
            }
            v.clear();
        }
        cout << sym << '\n';
    }
}