#include <iostream>
using namespace std;

int main() {
    string spend = "You are speeding and your fine is $";
    string pass = "Congratulations, you are within the speed limit!";
    int speed, record; cin >> speed >> record;
    if (speed < record) {
        if (record-speed <= 20) cout << spend << 100 << '.';
        else if (record-speed <= 30) cout << spend << 270 << '.';
        else cout << spend << 500 << '.'; 
    }
    else cout << pass;
}