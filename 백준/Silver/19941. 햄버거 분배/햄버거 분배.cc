#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    vector<char> table(N+1);

    string input; cin >> input;
    for (int i = 1; i <= N; i++) {
        table[i] = input[i-1];
    }

    int count = 0;
    for (int i = 1; i <= N; i++) {
        if (table[i] == 'P') {
            for (int d = i-K; d <= i+K; d++) {
                if (0 < d && d <= N && table[d] == 'H') {
                    table[d] = '0';
                    count++;
                    break;
                }
            }
        }
    }

    cout << count;
}