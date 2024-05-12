#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double long A, B, C, D; cin >> A >> B >> C >> D;

    int rotate = 0;
    double long value = (A/C) + (B/D);
    double long tmp;

    tmp = C/D + A/B;
    if (tmp > value) {
        rotate = 1;
        value = tmp;
    }
    tmp = D/B + C/A;
    if (tmp > value) {
        rotate = 2;
        value = tmp;
    }
    tmp = B/A + D/C;
    if (tmp > value) {
        rotate = 3;
        value = tmp;
    }


    cout << rotate; 

}