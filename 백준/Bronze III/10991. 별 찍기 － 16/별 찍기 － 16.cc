#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        // 처음 공백 및 별
        for (int b = 0; b < N-i; b++) cout << ' ';
        cout << '*';

        // 나머지 별
        for (int s = 0; s < i-1; s++) cout << " *";
        cout << '\n';
    }
}