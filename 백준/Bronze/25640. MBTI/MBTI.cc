#include <iostream>
using namespace std;

int main() {
    string my; cin >> my;
    int N; cin >> N;

    int count = 0;
    for (int i = 0; i < N; i++) {
        string fr; cin >> fr;
        if (my == fr) count++;
    }

    cout << count;
}