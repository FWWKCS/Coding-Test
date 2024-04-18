#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> person(1, 0);

    int p;
    for (int i = 0; i < 4; i++) {
        cin >> p;
        person.push_back(p);
    }

    int x, y, r;
    cin >> x >> y >> r;
    for (int i = 1; i <= 4; i++) {
        if (person[i] == x) {
            cout << i;
            return 0;
        } 
    }

    cout << 0;
}