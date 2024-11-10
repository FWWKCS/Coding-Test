#include <iostream>
using namespace std;

int main() {
    int T; cin >> T;
    int answer = 0;
    for (int i = 0; i < 5; i++) {
        int x; cin >> x;
        if (x == T) answer++;
    }
    cout << answer;
}