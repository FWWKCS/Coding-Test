#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int C; cin >> C;
    for (int i = 1; i <= C; i++) {
        int a, b, c, d, e; cin >> a >> b >> c >> d >> e;
        vector<int> l = {a, b, c, d, e};
        sort(l.rbegin(), l.rend());
        cout << "Case #" << i << ": " << l[0] << '\n';
    }
}