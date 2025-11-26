#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int A, B, C; cin >> A >> B >> C;
    
    cout << min(A, N) + min(B, N) + min(C, N);
}