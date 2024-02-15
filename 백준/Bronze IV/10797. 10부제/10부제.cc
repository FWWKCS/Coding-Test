#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int N; cin >> N;
    vector<int> cars(5);
    for (int i = 0; i < 5; i++) cin >> cars[i];
    int count = 0;
    for (int i = 0; i < 5; i++) {
        if (cars[i] == N) count++;
    }
    cout << count;
}