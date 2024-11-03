#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int a, b, c; cin >> a >> b >> c;
    vector<int> t = {a, b, c};
    sort(t.begin(), t.end());

    if (t[0] == t[1] && t[1] == t[2]) cout << 2;
    else if ((t[0]*t[0])+(t[1]*t[1]) == (t[2]*t[2])) cout << 1;
    else cout << 0;
}