#include <iostream>
using namespace std;

int main() {
    int n; cin >> n;

    // 엄지 일반항
    // x_n = 1+8(n-1)

    // 검지 일반항
    // 홀수항: xe_n = 2+8(n-1)
    // 짝수항: xo_n = 8+8(n-1)

    // 중지 일반항
    // 3+4(n-1)

    // 약지 일반항
    // 홀수항: xe_n = 4+8(n-1)
    // 짝수항: xe_n = 6+8(n-1)

    // 소지 일반항
    // 5+8(n-1)

    if (n <= 5) cout << n;
    else if (n < 5 && n < 9) {
        if (n == 6) cout << 4;
        else if (n == 7) cout << 3;
        else cout << 2;
    } 
    else {
        // 엄지 
        if ((n-1) % 8 == 0) cout << 1;
        // 검지 
        else if ((n-2) % 8 == 0 || (n-8) % 8 == 0) cout << 2;
        // 중지
        else if ((n-3) % 4 == 0) cout << 3;
        // 소지
        else if ((n-4) % 8 == 0 || (n-6) % 8 == 0) cout << 4;
        // 약지
        else cout << 5; 
    }
}