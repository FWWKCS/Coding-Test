#include <bits/stdc++.h>
using namespace std;

int main(void) {
    vector<int> sequence(1001, 0);
    int value = 1, idx = 1;
    while (idx <= 1000) {
        for (int i = 0; i < value; i++) {
            sequence[idx] = value;
            idx++;
        }
        value++;
    }

    int A, B; cin >> A >> B;
    int sum = 0;
    for (int i = A; i <= B; i++) {
        sum += sequence[i];
    }
    cout << sum;
}