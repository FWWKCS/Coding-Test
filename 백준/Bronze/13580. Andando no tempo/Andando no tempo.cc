#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int A, B, C; cin >> A >> B >> C;
    vector<int> e = {A, B, C};
    sort(e.begin(), e.end());

    if (e[0]+e[1] == e[2] 
        || e[0] == e[1] 
        || e[1] == e[2]) cout << "S";
    else cout << "N";
}