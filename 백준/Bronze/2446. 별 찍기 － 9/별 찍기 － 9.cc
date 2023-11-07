#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    // 감소층 출력
    for (int i = N; i >= 1; i--) {
        // 공백 출력
        for (int b = 1; b <= N-i; b++) cout << " ";
        // 별 출력
        for (int s = 1; s <= (2*i)-1; s++) cout << "*";
        // 개행
        cout << '\n';
    }
    // 증가층 출력
    for (int i = 2; i <= N; i++) {
        // 공백 출력
        for (int b = 1; b <= N-i; b++) cout << " ";
        // 별 출력
        for (int s = 1; s <= (2*i)-1; s++) cout << "*";
        // 개행
        cout << '\n';
    }
}