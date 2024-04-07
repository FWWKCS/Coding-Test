#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N, K; cin >> N >> K;
    string seq; cin >> seq;
    seq += ',';

    vector<int> B;

    string num = "";
    for (int i = 0; i < seq.length(); i++) {
        if (seq[i] == ',') {
            B.push_back(stoi(num));
            num = "";
        }
        else num += seq[i];
    }

    for (int i = 0; i < K; i++) {
        for (int j = 0; j < N-1-i; j++) {
            B[j] = B[j+1] - B[j];
        }
    }

    for (int i = 0; i < N-K; i++) {
        cout << B[i];
        if (i != N-K-1) cout << ',';
    }
}