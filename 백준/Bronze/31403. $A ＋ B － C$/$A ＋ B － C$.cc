#include <iostream>
using namespace std;

int main() {
    string A, B, C; cin >> A >> B >> C;
    cout << stoi(A) + stoi(B) - stoi(C) << '\n';
    
    A += B;
    cout << stoi(A) - stoi(C);
}