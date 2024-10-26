#include <iostream>
using namespace std;

int main() {
    double w, h; cin >> w >> h;
    double BMI = w/(h*h);
    if (BMI > 25) cout << "Overweight";
    else if (18.5 <= BMI && BMI <= 25) cout << "Normal weight";
    else cout << "Underweight";
}