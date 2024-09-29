#include <iostream>
typedef long long ll;
using namespace std;

ll A, B, T;

int main() {
    cin >> A >> B;

    if (A < B) T = (B-A+1)*(A+B)/2;
    else T = (A-B+1)*(A+B)/2;
    
    cout << T;
}