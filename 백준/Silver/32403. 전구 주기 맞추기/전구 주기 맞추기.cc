#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, T; cin >> N >> T;
    vector<int> A(N);
    for (auto &r : A) cin >> r;

    // 각 수를 T의 약수가 되게해야함
    int answer = 0;

    for (int a : A) {
        // 감소
        int dsc = 0;
        int d = a;
        while (d >= 1 && T % d != 0) {
            d--;
            dsc++;
        }

        // 증가
        int asc = 0;
        int u = a;
        if (u > T) asc = 1e9;
        while (u <= T && T % u != 0) {
            u++;
            asc++;
        }

        // cout << a << ' ' << dsc << ' ' << asc << '\n';
        answer += min(dsc, asc);
    }

    cout << answer;
}