#include <iostream>
using namespace std;

int main() {
    int H, W, N, M; cin >> H >> W >> N >> M;
    int r, c;
    if (H % (N+1) == 0) r = H / (N+1);
    else r = H / (N+1) + 1;

    if (W % (M+1) == 0) c = W / (M+1);
    else c = W / (M+1) + 1;

    cout << r*c;
}