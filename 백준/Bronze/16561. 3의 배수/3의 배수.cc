#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    int answer = 0;
    for (int x = N-3; x >= 3; x -= 3) {
        for (int y = N-3; y >= 3; y -= 3) {
            if (N-x-y > 0) answer++;
        }
    }

    cout << answer;
}