#include <bits/stdc++.h>
using namespace std;

int main() {
    int N; cin >> N;

    int time = 0, current = 1;
    while (N != 0) {
        if (N < current) {
            current = 1;
            continue;
        }
        N -= current;
        current++;
        time++;
    }

    cout << time;
}