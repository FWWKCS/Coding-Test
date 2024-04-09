#include <iostream>
using namespace std;

int main() {
    int Aa, Al;
    int Ba, Bl;

    cin >> Aa >> Al >> Ba >> Bl;

    while (true) {
        Al -= Ba;
        Bl -= Aa;

        if (Al > 0 && Bl <= 0) {
            cout << "PLAYER A";
            break;
        }
        else if (Al < 0 && Bl > 0) {
            cout << "PLAYER B";
            break;
        }
        else if (Al < 0 && Bl < 0) {
            cout << "DRAW";
            break;
        }
    }
}