#include <iostream>
using namespace std;

int main() {
    int N; cin >> N;

    int count;

    if (N < 2023) count = 0;
    else if (N == 2023) count = 1;
    else {
        count = 1;
        for (int i = 12023; i <= N; i++) {
            string v = to_string(i);
            bool cond1 = false, cond2 = false, cond3 = false, cond4 = false;
            for (int j = 0; j < v.length(); j++) {
                if (!cond1 && v[j] == '2') cond1 = true;
                else if (cond1 && v[j] == '0') cond2 = true;
                else if (cond2 && v[j] == '2') cond3 = true;
                else if (cond3 && v[j] == '3') cond4 = true;
            }

            if (cond4) count++;
        }
    }

    cout << count;
}