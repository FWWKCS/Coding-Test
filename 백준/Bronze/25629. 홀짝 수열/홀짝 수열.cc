#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N; cin >> N;
    vector<int> odd, even;

    for (int i = 0; i < N; i++) {
        int x; cin >> x;
        if (x % 2 == 0) even.push_back(x);
        else odd.push_back(x);
    }

    if (N % 2 == 1 && odd.size() != even.size()+1) cout << 0;
    else if (N % 2 == 0 && odd.size() != even.size()) cout << 0;
    else cout << 1;
}
