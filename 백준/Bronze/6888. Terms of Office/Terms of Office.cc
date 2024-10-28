#include <iostream>
using namespace std;

int main() {
    int X, Y; cin >> X >> Y;

    for (int i = X; i <= Y; i += 60) {
        cout << "All positions change in year " << i << '\n';
    }
}