#include <iostream>
using namespace std;

int main() {
    string A, B; cin >> A >> B;
    int col = abs((B[0]-'a') - (A[0]-'a'));
    int row = abs((B[1]-'0') - (A[1]-'0'));

    if (col <= row) cout << col << ' ' << row;
    else cout << row << ' ' << col;
    return 0;
}