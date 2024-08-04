#include <iostream>
using namespace std;

int main() {
    long long N, K; cin >> N >> K;

    long long answer = N * N * K;
    cout << (long long)answer;
}