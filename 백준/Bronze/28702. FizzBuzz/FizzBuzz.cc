#include <iostream>
#include <vector>
using namespace std;

int main() {
    string x;
    int target;
    for (int i = 0; i < 3; i++) {
        cin >> x;
        if (x != "Fizz" && x != "Buzz" && x != "FizzBuzz") {
            target = stoi(x) + (3 - i);
        }
    }

    if (target % 3 == 0 && target % 5 == 0) cout << "FizzBuzz";
    else if (target % 3 == 0 && target % 5 != 0) cout << "Fizz";
    else if (target % 3 != 0 && target % 5 == 0) cout << "Buzz";
    else cout << target;
    
}