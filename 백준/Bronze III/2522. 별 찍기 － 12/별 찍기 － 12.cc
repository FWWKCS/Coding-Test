#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;

    // 상위 N층
    for (int i = 0; i < N; i++) {
        // 공백
        for (int b = 0; b < N-1-i; b++) cout << ' ';
        // 별
        for (int s = 0; s < i+1; s++) cout << '*';
        cout << '\n';
    }

    // 하위 N-1층
    for (int i = 0; i < N-1; i++) {
        // 공백
        for (int b = 0; b < i+1; b++) cout << ' ';
        // 별
        for (int s = 0; s < N-1-i; s++) cout << '*';
        cout << '\n';
    }
}