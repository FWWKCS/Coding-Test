#include <iostream>
#include <string>
using namespace std;

int main() {
    int N; cin >> N;
    string S; cin >> S;
    int even = 0, odd = 0;
    for (int i = 0; i < N; i++) {
        if ((S[i] - '0') % 2 == 0) even++;
        else odd++;
    }
    
    if (even > odd) cout << 0;
    else if (even < odd) cout << 1;
    else cout << -1;
}