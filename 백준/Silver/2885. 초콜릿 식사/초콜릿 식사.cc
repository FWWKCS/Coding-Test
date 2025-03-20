#include <iostream>
#include <bitset>
#include <math.h>
using namespace std;

int main() {
    int K; cin >> K;
    int exp = log2(K);
    if (pow(2, exp) < K) exp += 1;
    
    cout << (int)pow(2, exp) << ' ';
    
    bitset<32> x(K);
    string b = x.to_string();
    int s = 31, e = 0;
    while (b[s] == '0') s--;
    while (b[e] == '0') e++;

    if (s > e) cout << s-e+1;
    else cout << s-e;
}