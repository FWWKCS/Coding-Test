#include <iostream>
#include <math.h>
using namespace std;

int main() {
    double A, B; cin >> A >> B;
    double M = (B-A)/400;

    cout << 1/(1+pow(10, M));
}