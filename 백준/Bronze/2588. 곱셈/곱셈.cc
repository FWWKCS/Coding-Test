#include <iostream>
using namespace std;

int main() {
    int a,b;
    cin >> a;
    cin >> b;

    int hundred = b / 100;
    int ten = (b % 100) / 10;
    int one = b % 10;

    cout << a * one << endl;
    cout << a * ten << endl;
    cout << a * hundred << endl;
    cout << a * b << endl;
}