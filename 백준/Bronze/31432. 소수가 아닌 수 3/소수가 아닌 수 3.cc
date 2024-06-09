#include <iostream>
#include <set>
#include <algorithm>
using namespace std;

int main() {
    int N; cin >> N;
    int x;
    set<int> d;
    for (int i = 0; i < N; i++) {
        cin >> x;
        d.insert(x);
    }

    // 0과 1은 소수가 아님
    if (d.find(0) != d.end()) {
        cout << "YES\n0";
        return 0;
    } 

    if (d.find(1) != d.end()) {
        cout << "YES\n1";
        return 0;
    }

    for (int k = 2; k <= 9; k++) {
        if (d.find(k) != d.end()) {
            cout << "YES\n" << k << k;
            return 0;
        }
    }

    cout << "NO";
}