#include <iostream>
#include <set>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N; cin >> N;
    set<char> even = {'0', '2', '4', '6', '8'};
    string K;
    for (int i = 0; i < N; i++) {
        cin >> K;
        if (even.find(K.back()) != even.end()) cout << "even\n";
        else cout << "odd\n";
    }
}