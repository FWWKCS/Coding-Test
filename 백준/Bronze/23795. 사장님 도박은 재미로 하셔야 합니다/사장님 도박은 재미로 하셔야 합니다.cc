#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int x;
    int total = 0;
    while (true) {
        cin >> x;
        if (x == -1) break;
        
        total += x;
    }
    cout << total;
}