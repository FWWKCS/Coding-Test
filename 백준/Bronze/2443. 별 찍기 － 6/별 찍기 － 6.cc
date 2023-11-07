#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    for (int i = N; i >= 1; i--) {
        // 공백 출력
        for (int b = 0; b < N-i; b++) cout << " ";
        // 별 출력
        for (int s = 0; s < (2*i)-1; s++) cout << "*";
        // 개행
        cout << '\n';
    }
}