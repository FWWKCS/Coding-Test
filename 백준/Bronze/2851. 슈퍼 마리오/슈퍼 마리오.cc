#include <iostream>
#include <vector>
using namespace std;

int main() {
    int k;
    vector<int> mushroom(11, 0);
    for (int i = 1; i <= 10; i++) {
        cin >> k;
        mushroom[i] = mushroom[i-1] + k;
    }

    if (mushroom.back() < 100) {
        cout << mushroom.back();
        return 0;
    }

    int x, y;
    for (int i = 1; i <= 10; i++) {
        if (mushroom[i] == 100) {
            cout << mushroom[i];
            return 0;
        }
        else if (mushroom[i] > 100) {
            x = mushroom[i-1];
            y = mushroom[i];
            break;
        }
    }

    if ((100-x) < (y-100)) cout << x;
    else cout << y;
}