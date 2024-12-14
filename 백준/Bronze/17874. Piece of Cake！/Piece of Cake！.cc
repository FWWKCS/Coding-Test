#include <iostream>
using namespace std;

int main() {
    int n, h, v; cin >> n >> h >> v;
    int answer;

    answer = max(h*v, max((n-h)*v, max(h*(n-v), (n-h)*(n-v)))) * 4;
    cout << answer;
}