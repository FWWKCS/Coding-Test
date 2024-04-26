#include <iostream>
#include <vector>
using namespace std;

int main() {
    int D, K; cin >> D >> K;
    vector<int> x = {0,1,0};
    vector<int> y = {0,0,1};
    for (int d = 0; d < D-2; d++) {
        int dx = y.back();
        int dy = x.back()+y.back();

        x.push_back(dx);
        y.push_back(dy);
    }

    for (int a = 1; a <= K / x.back(); a++) {
        if ((K-(x.back() * a)) % y.back() == 0) {
            cout << a << '\n' << (K-(x.back() * a)) / y.back();
            return 0;
        }
    }
}