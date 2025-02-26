#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    int x, y; cin >> x >> y;

    if (N == 1) {
        cout << 0;
        return 0;
    }

    int answer = 4;
    if (x == 1 || x == N) answer--;
    if (y == 1 || y == N) answer--;

    cout << answer;
}