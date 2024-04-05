#include <iostream>
#include <math.h>
using namespace std;

int main() {
    int N; cin >> N;
    int count = 0;
    for (int B = 1; B <= 500; B++) {
        for (int A = B; A <= 500; A++) {
            if (pow(B, 2) + N == pow(A, 2)) count++;
        }
    }

    cout << count;
}