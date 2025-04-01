#include <iostream>
using namespace std;

int T, E, N, x;

int main() {
    cin >> T;
    while (T--) {
        cin >> E >> N;
        int emp = 0;
        while (N--) {
            cin >> x;
            if (x > E) emp++;
        }
        cout << emp << '\n';
    }
}