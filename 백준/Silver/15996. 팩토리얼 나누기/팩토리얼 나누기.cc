#include <iostream>
using namespace std;

int main() {
    int N, A; cin >> N >> A;

    int m = N / A;
    long long count = m; 
    while (m >= A) {
        m /= A;
        count += m;
    }

    cout << count;
}