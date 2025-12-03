#include <iostream>
#define FASTIO ios::sync_with_stdio(0), cin.tie(0)
using namespace std;

int main() {
    FASTIO;

    int N; cin >> N;
    int answer = 0;
    while (N--) {
        int x; cin >> x;
        answer = max(answer, x);
    }

    cout << answer;
}