#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    if (N == 1) cout << "YES\n1";
    else if (N == 2) cout << "NO";
    else {
        int arr[N] = {1, 3, 2, };
        
        for (int i = 3; i < N; i++) arr[i] = i+1;
        
        cout << "YES\n";
        for (auto x : arr) cout << x << ' ';
    }
}