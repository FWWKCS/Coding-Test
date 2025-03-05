#include <iostream>
using namespace std;

int main() {
    int A, T, X; cin >> A >> T >> X;

    int term = 1;
    int cnt0 = 0, cnt1 = 0;
    int cur = -1;

    while (true) {
        // 뻔
        cnt0++; cur = (cur + 1) % A;
        if (X == 0 && cnt0 == T) {
            cout << cur;
            return 0;
        }

        // 데기
        cnt1++; cur = (cur + 1) % A;
        if (X == 1 && cnt1 == T) {
            cout << cur;
            return 0;
        }

        // 뻔
        cnt0++; cur = (cur + 1) % A;
        if (X == 0 && cnt0 == T) {
            cout << cur;
            return 0;
        }

        // 데기
        cnt1++; cur = (cur + 1) % A;
        if (X == 1 && cnt1 == T) {
            cout << cur;
            return 0;
        }

        // 뻔 x (term+1)번
        for (int i = 0; i < term + 1; i++) {
            cnt0++; cur = (cur + 1) % A;
            if (X == 0 && cnt0 == T) {
                cout << cur;
                return 0;
            }
        }

        // 데기 x (term+1)번
        for (int i = 0; i < term + 1; i++) {
            cnt1++; cur = (cur + 1) % A;
            if (X == 1 && cnt1 == T) {
                cout << cur;
                return 0;
            }
        }
        
        term++;
    } 
}