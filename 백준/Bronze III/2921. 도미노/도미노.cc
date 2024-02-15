#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;
    int total = 0;
    for (int i = 1; i <= N; i++) {
        for (int j = 0; j <= i; j++) total += i+j;
    }
    cout << total;
}