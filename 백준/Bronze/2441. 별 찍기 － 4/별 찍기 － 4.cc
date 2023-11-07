#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = N; i > 0; i--) {
        // 공백 출력
        for (int b = 0; b < N-i; b++) cout << " ";
        // 별 출력
        for (int s = 0; s < i; s++) cout << "*";
        // 개행
        cout << '\n';
    }
}