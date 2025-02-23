#include <iostream>
#include <set>
using namespace std;
using ll = long long;

set<ll> num;
ll N, M;

void recursion(ll cur) {
    if (num.find(cur) != num.end()) return;
    num.insert(cur);

    if (cur == 1) return;


    if (cur % 2 == 0) {
        recursion(cur / 2);
        num.insert((cur/2));
    }
    else {
        recursion((cur-1)/2);
        num.insert((cur-1)/2);

        recursion((cur-1)/2 + 1);
        num.insert((cur-1)/2 +1);
    }
}

int main() {
    cin >> N >> M;

    recursion(N);

    cout << (num.find(M) != num.end() ? "YES" : "NO");
}