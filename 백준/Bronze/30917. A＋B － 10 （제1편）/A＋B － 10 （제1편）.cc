#include <iostream>
using namespace std;

int main() {
    int A = 0, B = 0;
    for (int i = 1; i <= 9; i++) {
        cout << "? A " << i << endl;
        int response; cin >> response;
        if (response) {
            A = i;
            break;
        }
    }

    for (int i = 1; i <= 9; i++) {
        cout << "? B " << i << endl;
        int response; cin >> response;
        if (response) {
            B = i;
            break;
        }
    }

    cout << "! " << A+B;
}