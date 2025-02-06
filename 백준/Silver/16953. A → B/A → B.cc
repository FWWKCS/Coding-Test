#include <iostream>
using namespace std;
using ll = long long;

ll A, B;
int answer = 1e9;

void recursion(int depth, ll current) {
    if (current > 1'000'000'000) return;

    if (current == B) {
        answer = min(answer, depth);
        return;
    }

    // x2
    recursion(depth+1, current*2);

    // add 1
    recursion(depth+1, (current*10)+1);
}

int main() {
    cin >> A >> B;

    recursion(1, A);

    cout << ((answer != 1e9) ? answer : -1);
}