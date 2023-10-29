#include <iostream>
using namespace std;

int main() {
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);

    int testcase, a, b;
    cin >> testcase;

    for (int i = 0; i < testcase; i++) {
        cin >> a >> b;
        cout << a+b << '\n';
    }
}