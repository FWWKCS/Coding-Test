#include <iostream>
using namespace std;

int main() {
    int x1, y1; cin >> x1 >> y1;
    int x2, y2; cin >> x2 >> y2;
    int x3, y3; cin >> x3 >> y3;

    // 외적
    int cross = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);

    if (cross > 0) cout << 1;
    else if (cross < 0) cout << -1;
    else cout << 0;
}