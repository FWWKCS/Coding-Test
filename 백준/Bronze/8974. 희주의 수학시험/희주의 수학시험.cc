#include <bits/stdc++.h>
using namespace std;

int main() {
    int A, B; cin >> A >> B;
    vector<int> sequence(1, 0);
    
    int count = 1;
    for (int i = 1; i <= 1000; i++) {
        for (int k = 0; k < count; k++) sequence.push_back(count);
        count++;
    }

    cout << accumulate(sequence.begin()+A, sequence.begin()+B+1, 0);
}