#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;
    for (int i = 1; i <= N; i++) {
        // 홀수 행
        if (i % 2 != 0) {
            for (int j = 1; j < N; j++) cout << "* ";
            cout << "*\n";
        } else {
            for (int j = 0; j < N; j++) cout << " *";
            cout << '\n';
        }
    }
}