#include <iostream>
#include <vector>
using namespace std;

int main() {
    // a ^ b = c 이면, a = b ^ c 또는 b = a ^ c

    int N; cin >> N;
    int input;
    vector<int> a, b;
    for (int i = 0; i < N; i++) {
        cin >> input;
        a.push_back(input);
    }

    for (int i = 0; i < N; i++) {
        cin >> input;
        b.push_back(input);
    }

    int x;
    int count = 0;
    for (int i = 0; i < N-1; i++) {
        if (a[i] != b[i]) {
            x = a[i] ^ b[i];
            a[i] = a[i] ^ x;
            a[i+1] = a[i+1] ^ x;

            count++;
        }
    }

    for (int i = 0; i < N; i++) {
        if (a[i] != b[i]) {
            cout << -1; 
            return 0;
        }
    }

    cout << count;
}