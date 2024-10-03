#include <iostream>
using namespace std;

int main() {
    int n, m; cin >> n >> m;

    int count = 0;
    for (int c = 0; c <= n+m; c++) {
        for (int a = 0; a <= n; a++) {
            for (int b = 0; b <= m; b++) {
                if (a+b == c) count++;
            }
        }
    }
    cout << count;
}