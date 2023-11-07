#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    // 증가층 출력
    for (int i = 1; i <= N; i++) {
        // 왼쪽 별 출력
        for (int s = 1; s <= i; s++) cout << "*";
        // 공백 출력
        for (int b = 1; b <= (N-i)*2; b++) cout << " ";
        // 오른쪽 별 출력
        for (int s = 1; s <= i; s++) cout << "*";
        // 개행
        cout << '\n';
    }
    // 감소층 출력
    for (int i = N-1; i >= 1; i--) {
        // 왼쪽 별 출력
        for (int s = 1; s <= i; s++) cout << "*";
        // 공백 출력
        for (int b = 1; b <= (N-i)*2; b++) cout << " ";
        // 오른쪽 별 출력
        for (int s = 1; s <= i; s++) cout << "*";
        // 개행
        cout << '\n';
    }
}