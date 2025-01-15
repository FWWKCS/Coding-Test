#include <iostream>
#define MOD 14579
using namespace std;

int main() {
    unsigned long long a, b; cin >> a >> b;

    unsigned long long answer = 1;
    for (unsigned long long i = a; i <= b; i++) {
        // i*(i+1)/2 계산 시 모듈러 연산 적용
        unsigned long long sum = i * (i + 1) / 2;

        // 누적 곱
        answer = (answer * sum) % MOD;
    }

    cout << answer;
    return 0;
}
