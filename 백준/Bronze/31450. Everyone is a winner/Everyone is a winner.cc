#include <iostream>
using namespace std;

int main() {
    int M, N; cin >> M >> N;
    
    if (M % N == 0) cout << "Yes";
    else cout << "No";
}