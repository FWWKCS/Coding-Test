#include <iostream>
#include <math.h>
#include <string>
#define MAX 100'000'000
using namespace std;

int main() {
    int N; cin >> N;

    long long count = 0;
    for (int i = 1; i <= 8; i++) {
        count += 9 * (i) * pow(10, i-1);
        if (N <= count) {
            count -= 9 * (i) * pow(10, i-1);
            int quot, remain;
            int pos = N - count;
            int target;

            if (pos % i == 0) {
                quot = pos / i;
                target = pow(10, i-1) + quot - 1;
                cout << to_string(target)[i-1];
            }
            else {
                quot = pos / i;
                remain = pos % i;
                target = pow(10, i-1) + quot;
                cout << to_string(target)[remain-1];
            }

            break;
        }
    }
}