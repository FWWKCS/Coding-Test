#include <iostream>
#include <math.h>
using namespace std;
using ld = long double;
using ll = long long;

int main() {
    ld n, k; cin >> n >> k;

    // 실근 체크
    ld C = k - (n + 1);
    if (n*n - 4*C < 0) {
        cout << "NO";
        return 0;
    } 

    // 근이 정수인지 체크 (2의 배수)
    ld s1 = n - (ld)sqrt(n*n - 4*C);
    ld s2 = n + (ld)sqrt(n*n - 4*C);

    if ((s1 >= 0 && s1 == (ll)s1 && (ll)s1 % 2 == 0) 
     || (s2 >= 0 && s2 == (ll)s2 && (ll)s2 % 2 == 0)) {
        cout << "YES";
    } else {
        cout << "NO";
    }
}