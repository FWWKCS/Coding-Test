#include <iostream>
using namespace std;

int main() {
    int A, B, C;
    cin >> A >> B >> C;
    cout << (A+B)%C << " ";
    cout << ((A%C) + (B%C))%C << " ";
    cout << (A*B)%C << " ";
    cout << ((A%C) * (B%C))%C;
}