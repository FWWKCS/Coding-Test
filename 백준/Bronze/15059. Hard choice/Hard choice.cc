#include <iostream>
using namespace std;

int main() {
    int ca, ba, pa; cin >> ca >> ba >> pa;
    int cr, br, pr; cin >> cr >> br >> pr;

    int count = 0;
    if (cr > ca) count += cr-ca;
    if (br > ba) count += br-ba;
    if (pr > pa) count += pr-pa;

    cout << count;
}