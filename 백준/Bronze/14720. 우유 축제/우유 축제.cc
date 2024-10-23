#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int info[N];
    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        info[i] = x;
    }

    int cur = 0;
    int count = 0;
    for (int i = 0; i < N; i++) {
        if (info[i] == cur) {
            count++;
            cur = (cur + 1) % 3;
        }
    }
    cout << count;
}