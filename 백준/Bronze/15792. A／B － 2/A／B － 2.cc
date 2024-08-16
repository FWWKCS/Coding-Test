#include <bits/stdc++.h>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main() {
    FASTIO;

    int A, B; cin >> A >> B;

    // 정수부
    cout << A/B << ".";

    A %= B;

    // 실수부
    for (int i = 0; i <= 1000; i++) {
        A *= 10;
        cout << A/B;
        A -= (A/B) * B;
    }
}