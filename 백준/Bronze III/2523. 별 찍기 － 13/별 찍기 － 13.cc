#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;

    // 상위 N층
    for (int i = 0; i < N; i++) {
        // 별
        for (int s = 0; s < i+1; s++) cout << '*';
        cout << '\n';
    }

    // 하위 N층
    for (int i = 0; i < N-1; i++) {
        // 별
        for (int s = 0; s < N-1-i; s++) cout << '*';
        cout << '\n';
    }
}