#include <iostream>
using namespace std;

int main() {
    int a, b, c, d;
    
    for (int i = 0; i < 3; i++) {
        cin >> a >> b >> c >> d;

        switch (a+b+c+d) {
            case 0: 
                cout << "D\n";
                break;
            case 1:
                cout << "C\n";
                break;
            case 2:
                cout << "B\n";
                break;
            case 3:
                cout << "A\n";
                break;
            default:
                cout << "E\n"; 
        }
    }
}