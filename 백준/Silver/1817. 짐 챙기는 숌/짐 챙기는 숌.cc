#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N, M; cin >> N >> M;
    int boxes = 0, cur = 0;
    while (N--) {
        int x; cin >> x;
        if (cur + x <= M) cur += x;
        else {
            boxes++;
            cur = x;
        }
    }

    if (cur > 0) boxes++;

    cout << boxes;
}