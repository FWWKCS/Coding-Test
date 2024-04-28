#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);

    int T; cin >> T;
    for (int i = 0; i < T; i++) {
        int hp, mp, att, def, e1, e2, e3, e4;
        cin >> hp >> mp >> att >> def >> e1 >> e2 >> e3 >> e4;

        cout << max(1, hp+e1) + (max(1, mp+e2) * 5) + (max(0, att+e3) * 2) + ((def+e4) * 2) << '\n';
    }
}
