#include <iostream>
using namespace std;

int main() {
    int num[7];
    for (int i = 0; i < 7; i++) {
        cin >> num[i];
    }

    int sum = 0;
    int min = 9999;
    for (int i = 0; i < 7; i++) {
        if (num[i] % 2 != 0) {
            sum += num[i];
            if (num[i] < min) {
                min = num[i];
            }
        }
    }

    if (sum == 0) {
        cout << -1;
    }
    else {
        cout << sum << '\n' << min;
    }
}