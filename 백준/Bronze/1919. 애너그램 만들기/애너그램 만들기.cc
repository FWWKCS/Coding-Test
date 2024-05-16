#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string X, Y; cin >> X >> Y;
    vector<int> A(26, 0), B(26, 0);

    for (int i = 0; i < X.length(); i++) 
        A[int(X[i])-97]++;

    for (int i = 0; i < Y.length(); i++)
        B[int(Y[i])-97]++;

    int count = 0;
    for (int i = 0; i < 26; i++) 
        count += abs(A[i]-B[i]);
    
    cout << count;
    
}