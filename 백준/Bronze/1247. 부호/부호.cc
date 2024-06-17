#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int N;
    for (int i = 0; i < 3; i++) {
        cin >> N; 
        long long sum = 0;
        long long prev;
        int flow = 0;
        long long input;
        for (int k = 0; k < N; k++) {
            cin >> input;
            prev = sum;
            sum += input;
            if (input > 0 && prev > 0 && sum < 0) flow++; // 양수 오버플로
            else if (input < 0 && prev < 0 && sum > 0) flow--; // 음수 오버플로
        }

        if (flow == 0) {
            if (sum == 0) cout << "0\n";
            else {
                if (sum > 0) cout << "+\n";
                else cout << "-\n";
            }
        }
        else {
            if (flow > 0) cout << "+\n";
            else cout << "-\n";
        }
    }
}