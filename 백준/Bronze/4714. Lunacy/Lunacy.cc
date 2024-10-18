#include <iostream>
#include <iomanip>
using namespace std;

int main() {
    double x; 
    while (true) {
        cin >> x;
        if (x == -1.0) return 0;

        cout << fixed << setprecision(2) 
             << "Objects weighing " << x 
             << " on Earth will weigh " << x*0.167 
             << " on the moon.\n"; 
    }
}