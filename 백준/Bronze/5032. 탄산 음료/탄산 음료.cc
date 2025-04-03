#include <iostream>
using namespace std;

int e, f, c;

int main() {
    cin >> e >> f >> c;

    int answer = 0;
    int cur = e + f;
    while (cur >= c) {
        int b = cur / c;
        answer += b;
        cur = (cur % c) + b;
    }
    
    cout << answer;
}