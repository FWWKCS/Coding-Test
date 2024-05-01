#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int lcm(int a, int b) {
    return a / __gcd(a, b) * b;
}

int main() {
    vector<int> num;
    int x;
    int answer = 10e9;
    for (int i = 0; i < 5; i++) {
        cin >> x;
        num.push_back(x);
    }
    
    for (int i = 0; i < 3; i++) {
        for (int j = i+1; j < 4; j++) {
            for (int k = j+1; k < 5; k++) {
                int v = lcm(lcm(num[i], num[j]), num[k]);
                answer = min(v, answer);
            }
        }
    }
    
    cout << answer;
}