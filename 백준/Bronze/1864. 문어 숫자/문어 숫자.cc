#include <iostream>
#include <cmath>
#include <map>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    map<char, int> code = {
        {'-', 0},
        {'\\', 1},
        {'(', 2},
        {'@', 3},
        {'?', 4},
        {'>', 5},
        {'&', 6},
        {'%', 7},
        {'/', -1}
    };

    string oct;
    while (true) {
        cin >> oct;
        if (oct == "#") break;

        int dec = 0;
        for (int i = 0; i < oct.length(); i++) {
            dec += code[oct[i]] * pow(8, oct.length()-1-i);
        }

        cout << dec << '\n';
    }
}