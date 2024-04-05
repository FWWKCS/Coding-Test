#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

int main() {
    int T; cin >> T;
    int x;
    vector<int> seq(31, 0);
    for (int i = 1; i <= 30; i++) {
        seq[i] = seq[i-1] + pow(2, i-1);
    }

    for (int i = 0; i < T; i++) {
        cin >> x;
        cout << seq[x] << '\n';
    }
}