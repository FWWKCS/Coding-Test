#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;
    int answer = 1;
    for (int i = 2; i <= N; i++) answer = (answer * i) % 10;
    cout << answer;
}