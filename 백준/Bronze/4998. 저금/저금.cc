#include <iostream>
#include <sstream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    string line;
    double N, B, M;

    while (true) {
        if (!getline(cin, line)) break;
        
        istringstream iss(line);
        iss >> N >> B >> M;

        B /= 100;
        int count = 0;
        while (N < M) {
            N *= 1 + B;
            count++;
        }
        cout << count << '\n';
    }
}