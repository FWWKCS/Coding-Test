#include <iostream>
#include <string>
using namespace std;

int main() {
    string N; cin >> N;
    
    for (int s = 1; s < N.length(); s++) {
        int L = 1, R = 1;

        for (int l = 0; l < s; l++) L *= N[l] - '0';
        for (int r = s; r < N.length(); r++) R *= N[r] - '0';
        
        if (L == R) {
            cout << "YES\n";
            return 0;
        } 

    }
    cout << "NO\n";
}