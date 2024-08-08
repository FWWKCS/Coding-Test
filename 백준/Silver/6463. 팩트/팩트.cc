#include <iostream>
#include <cmath>
#define MAX 10'000
#define FASTIO ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

long long arr[MAX+1] = {0, };

int main() {
    FASTIO;

    arr[1] = 1;
    for (int i = 2; i <= MAX; i++) {
        arr[i] = arr[i-1] * i;

        while (arr[i] % 10 == 0) arr[i] /= 10;
        arr[i] %= 100'000;
    }

    int N;
    while (cin >> N) {
        for (int i = 0; i < 5-to_string(N).length(); i++) cout << ' ';
        cout << N;

        cout << " -> " << arr[N] % 10 << '\n';
    }
}