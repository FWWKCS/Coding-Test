#include <iostream>
#include <cmath>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

pair<int, int> comp(int dT, int h, int w) {
    int aH = 150, aW = 150;
    int minV = 100'000;
    for (int r = 1; r <= 150; r++) {
        for (int c = r+1; c <= 150; c++) {
            int v = pow(r, 2) + pow(c, 2);
            if (v > dT) {
                // 최솟값을 찾으면 무조건 초기화
                if (v < minV) {
                    aH = r; aW = c;
                    minV = v;
                }
                // 높이가 낮은 직사각형으로 갱신
                else if (v == minV && r < aH) {
                    aH = r; aW = c;
                }
            }
            else if (v == dT) {
                if (r > h) {
                    return make_pair(r, c);
                }
            }
        }
    }

    return make_pair(aH, aW);
}

int main() {
    FASTIO;
    
    while (true) {
        int h, w; cin >> h >> w;
        if (h == 0 && w == 0) break;

        int dT = pow(h, 2) + pow(w, 2);
        pair<int, int> v = comp(dT, h, w);
        cout << v.first << ' ' << v.second << '\n';
    }

}