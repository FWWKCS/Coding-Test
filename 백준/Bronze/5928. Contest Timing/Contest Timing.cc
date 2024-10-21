#include <iostream>
using namespace std;

int main() {
    int D, H, M; cin >> D >> H >> M;

    if ((D == 11 && H < 11) || (D == 11 && H == 11 && M < 11)) {
        cout << -1; 
        return 0;
    }
    else {
        int E = D * 24 * 60 + H * 60 + M;
        int S = 11*24*60 + 11*60 + 11;
        cout << E-S;
    }
}