#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int x, sum = 0;
    for (int i = 0; i < N; i++) {
        cin >> x;
        sum += x;
    }
    cout << sum;
}