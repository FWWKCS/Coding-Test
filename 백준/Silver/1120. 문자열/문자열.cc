#include <iostream>
using namespace std;

int main() {
    string X, Y; cin >> X >> Y;

    int total = 50;

    for (int i = 0; i < Y.length() - X.length() + 1; i++) {
        int count = 0;
        for (int k = 0; k < X.length(); k++) {
            if (X[k] != Y[i+k]) count++;
        }

        total = min(total, count);
    }

    cout << total;
}