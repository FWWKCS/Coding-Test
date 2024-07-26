#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

int main() {
    int N, K; cin >> N >> K;

    int answer = 0;
    for (int i = 1; i <= K; i++) {
        string v = to_string(N * i);
        reverse(v.begin(), v.end());
        answer = max(answer, stoi(v));
    }
    cout << answer;
}