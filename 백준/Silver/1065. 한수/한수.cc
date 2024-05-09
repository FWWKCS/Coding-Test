#include <iostream>
using namespace std;

int main() {
    int X; cin >> X;

    int count = 0;
    for (int i = 1; i <= X; i++) {
        if (i < 100) count++;
        else if (100 < i && i < 1000) {
            int a = (i / 100) - ((i % 100)/ 10);
            int b = ((i % 100) / 10) - (i % 10);

            if (a == b) count++;
        }
    }

    cout << count;
}