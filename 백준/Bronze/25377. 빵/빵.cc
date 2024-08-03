#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    int answer = 1'000'000;
    while (N--) {
        int A, B; cin >> A >> B;
        if (A <= B) answer = min(answer, B);
    }

    if (answer == 1'000'000) answer = -1;
    
    cout << answer;
}