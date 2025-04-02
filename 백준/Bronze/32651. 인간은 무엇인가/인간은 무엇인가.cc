#include <iostream>
using namespace std;

int N;
int main() {
    cin >> N;
    if (N <= 100'000 && N % 2024 == 0) {
        cout << "Yes";
    } else {
        cout << "No";
    }
}