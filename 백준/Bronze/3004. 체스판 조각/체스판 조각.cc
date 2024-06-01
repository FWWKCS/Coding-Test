#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> piece(101, 0);
    piece[0] = 1;
    piece[1] = 2;

    int d_o = 4;
    int even = 2;

    for (int i = 2; i <= 100; i++) {
        if (i % 2 == 0) {
            piece[i] = even * even;
            even++;
        }
        else {
            piece[i] = piece[i-2] + d_o;
            d_o += 2;
        }
    }

    int N; cin >> N;
    cout << piece[N];
}