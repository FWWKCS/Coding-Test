#include <iostream>
typedef long long ll; 
using namespace std;

int main() {
    ll A, B, C;
    ll X, Y, Z;
    cin >> A >> B >> C >> X >> Y >> Z;

    ll total = 0;

    if (A >= X) {
        total += X;
        A -= X;
        X = 0;
    }
    else {
        total += A;
        X -= A;
        A = 0;
    }

    if (B >= Y) {
        total += Y;
        B -= Y;
        Y = 0;
    } 
    else {
        total += B;
        Y -= B;
        B = 0;
    }

    if (C >= Z) {
        total += Z;
        C -= Z;
        Z = 0;
    }
    else {
        total += C;
        Z -= C;
        C = 0;
    }

    // printf("%d %d %d\n%d %d %d\n%d\n",A, B, C, X, Y, Z, total);


    ll q;
    // case 1. A -> B
    if (X != 0 && B != 0) {
        q = min(B, X / 3);
        B -= q;
        total += q;
        X -= q * 3;
    }   

    // case 2. B -> C
    if (Y != 0 && C != 0) {
        q = min(C, Y / 3);
        C -= q;
        total += q;
        Y -= q * 3;
    }

    // case 3. C -> A
    if (Z != 0 && A != 0) {
        q = min(A, Z / 3);
        A -= q;
        total += q;
        Z -= q * 3;
    }

    // case 4. A -> C
    if (X != 0 && C != 0) {
        q = min(C, X / 9);
        C -= q;
        total += q;
        X -= q * 9;
    }

    // case 5. B -> A
    if (Y != 0 && A != 0) {
        q = min(A, Y / 9);
        A -= q;
        total += q;
        Y -= q * 9;
    }

    // case 6. C -> B
    if (Z != 0 && B != 0) {
        q = min(B, Z / 9);
        B -= q;
        total += q;
        Z -= q * 9;
    }

    // printf("%d %d %d\n%d %d %d\n",A, B, C, X, Y, Z);

    cout << total;
}