#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    char T; 
    int W, H, L;

    int tW = 0, tC = 0;
    while (N--) {
        cin >> T >> W >> H >> L;
        if (T == 'A') {
            int count = (W/12) * (H/12) * (L/12);
            tW += 1000 + (500*count);
            tC += 4000 * count;
        } 
        else {
            tW += 6000;
        }
    }

    cout << tW << '\n' << tC;
}