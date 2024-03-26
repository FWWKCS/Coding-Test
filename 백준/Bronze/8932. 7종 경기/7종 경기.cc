#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int T; cin >> T;
    long long result;
    int x;

    vector<char> type = {'T', 'F', 'F', 'T', 'F', 'F', 'T'};
    vector<double> A = {9.23076, 1.84523, 56.0211, 4.99087, 0.188807, 15.9803, 0.11193};
    vector<double> B = {26.7, 75, 1.5, 42.5, 210, 3.8, 254};
    vector<double> C = {1.835, 1.348, 1.05, 1.81, 1.41, 1.04, 1.88};
        
    for (int i = 0; i < T; i++) {
        result = 0;
        for (int k = 0; k < type.size(); k++) {
            cin >> x;
            if (type[k] == 'T') result += floor(A[k]*pow(B[k]-x, C[k]));    
            else result += floor(A[k]*pow(x-B[k], C[k]));
        } 

        cout << result << '\n';
    }
}