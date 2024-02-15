#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int max = 0;
    int current = 0;
    int on, off;
    for (int i = 0; i < 4; i++) {
        cin >> off >> on;
        current = current - off + on;
        if (max < current) max = current;
    }
    cout << max;
}